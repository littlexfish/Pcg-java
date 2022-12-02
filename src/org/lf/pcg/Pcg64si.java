package org.lf.pcg;

import java.math.BigInteger;

public class Pcg64si implements Random.Random64 {
    
    private final PcgState.PcgState64 rng;
    
    public Pcg64si() {
        this(System.currentTimeMillis());
    }
    public Pcg64si(long seed) {
        rng = new PcgState.PcgState64(seed);
        Pcg.oneseq_64_srandom(rng, rng.state);
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
        Pcg.oneseq_64_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.oneseq_64_advance(rng, delta);
    }

    @Override
    public long nextLong() {
        return Pcg.oneseq_64_rxs_m_xs_64_random(rng);
    }

    @Override
    public BigInteger nextLong(BigInteger bound) {
        if(Pcg.checkOutBound64(bound)) return new BigInteger(Long.toUnsignedString(nextLong()));
        return new BigInteger(Long.toUnsignedString(Pcg.oneseq_64_rxs_m_xs_64_bounded(rng, bound.longValue())));
    }
}
