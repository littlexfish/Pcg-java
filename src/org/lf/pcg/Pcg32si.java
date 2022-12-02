package org.lf.pcg;

public class Pcg32si implements Random.Random32 {
    
    private final PcgState.PcgState32 rng;

    public Pcg32si() {
        this((int)System.currentTimeMillis());
    }
    public Pcg32si(int seed) {
        rng = new PcgState.PcgState32(seed);
        Pcg.oneseq_32_srandom(rng, rng.state);
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
        Pcg.oneseq_32_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.oneseq_32_advance(rng, delta);
    }

    @Override
    public int nextInt() {
        return Pcg.oneseq_32_rxs_m_xs_32_random(rng);
    }

    @Override
    public long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        return Integer.toUnsignedLong(Pcg.oneseq_32_rxs_m_xs_32_bounded(rng, (int)bound));
    }
}
