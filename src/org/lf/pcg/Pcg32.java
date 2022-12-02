package org.lf.pcg;

public class Pcg32 implements Random.Random32 {

    private final PcgSetseqState.PcgSetseqState64 rng;

    public Pcg32() {
        this(System.currentTimeMillis(), Pcg.getDefaultIncrement64());
    }
    public Pcg32(long seed) {
        this(seed, Pcg.getDefaultIncrement64());
    }
    public Pcg32(long seed, long seq) {
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
    public int nextInt() {
        return Pcg.setseq_64_xsh_rr_32_random(rng);
    }

    @Override
    public long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        return Integer.toUnsignedLong(Pcg.setseq_64_xsh_rr_32_bounded(rng, (int)bound));
    }
}
