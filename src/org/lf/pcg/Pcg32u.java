package org.lf.pcg;

public class Pcg32u implements Random.Random32 {

    private final PcgState.PcgState64 rng;

    public Pcg32u() {
        this(System.currentTimeMillis());
    }
    public Pcg32u(long seed) {
        rng = new PcgState.PcgState64(seed);
        Pcg.unique_64_srandom(rng, rng.state);
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
        Pcg.unique_64_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.unique_64_advance(rng, delta);
    }

    @Override
    public int nextInt() {
        return Pcg.unique_64_xsh_rr_32_random(rng);
    }

    @Override
    public long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        return Integer.toUnsignedLong(Pcg.unique_64_xsh_rr_32_bounded(rng, (int)bound));
    }
}
