package org.lf.pcg;

import java.math.BigInteger;

public class Pcg64i implements Random.Random64 {
    
    private final PcgSetseqState.PcgSetseqState64 rng;
    
    public Pcg64i() {
        this((int)System.currentTimeMillis(), Pcg.getDefaultIncrement64());
    }
    public Pcg64i(long seed) {
        this(seed, Pcg.getDefaultIncrement64());
    }
    public Pcg64i(long seed, long seq) {
        rng = new PcgSetseqState.PcgSetseqState64(seed, seq);
        Pcg.setseq_64_srandom(rng, rng.state, rng.inc);
    }
    
    @Override
    public void setState(Number st) {
        rng.state = st.longValue();
    }

    @Override
    public Number getState() {
        return rng.state;
    }

    @Override
    public void step() {
        Pcg.setseq_64_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.setseq_64_advance(rng, delta);
    }

    @Override
    public long nextLong() {
        return Pcg.setseq_64_rxs_m_xs_64_random(rng);
    }

    @Override
    public BigInteger nextLong(BigInteger bound) {
        if(Pcg.checkOutBound64(bound)) return new BigInteger(Long.toUnsignedString(nextLong()));
        return new BigInteger(Long.toUnsignedString(Pcg.setseq_64_rxs_m_xs_64_bounded(rng, bound.longValue())));
    }
}
