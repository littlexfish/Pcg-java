package org.lf.pcg;

public class Pcg32s implements Random.Random32 {

    private final PcgState.PcgState64 rng;

    public Pcg32s() {
        this(System.currentTimeMillis());
    }
    public Pcg32s(long seed) {
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
    public int nextInt() {
        return Pcg.oneseq_64_xsh_rr_32_random(rng);
    }

    @Override
    public long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        return Integer.toUnsignedLong(Pcg.oneseq_64_xsh_rr_32_bounded(rng, (int)bound));
    }
}
