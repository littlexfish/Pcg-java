package org.lf.pcg;

public class Pcg32i implements Random.Random32 {
    
    private final PcgSetseqState.PcgSetseqState32 rng;
    
    public Pcg32i() {
        this((int)System.currentTimeMillis(), Pcg.getDefaultIncrement32());
    }
    public Pcg32i(int seed) {
        this(seed, Pcg.getDefaultIncrement32());
    }
    public Pcg32i(int seed, int seq) {
        rng = new PcgSetseqState.PcgSetseqState32(seed, seq);
        Pcg.setseq_32_srandom(rng, rng.state, rng.inc);
    }
    
    @Override
    public void setState(Number st) {
        rng.state = st.intValue();
    }

    @Override
    public Number getState() {
        return rng.state;
    }

    @Override
    public void step() {
        Pcg.setseq_32_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.setseq_32_advance(rng, delta);
    }

    @Override
    public int nextInt() {
        return Pcg.setseq_32_rxs_m_xs_32_random(rng);
    }

    @Override
    public long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        return Integer.toUnsignedLong(Pcg.setseq_32_rxs_m_xs_32_bounded(rng, (int)bound));
    }
}
