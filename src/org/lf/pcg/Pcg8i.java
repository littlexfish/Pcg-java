package org.lf.pcg;

public class Pcg8i implements Random.Random8 {

    private final PcgSetseqState.PcgSetseqState8 rng;

    public Pcg8i() {
        this((int)System.currentTimeMillis(), Pcg.getDefaultIncrement8());
    }
    public Pcg8i(int seed) {
        this(seed, Pcg.getDefaultIncrement8());
    }
    public Pcg8i(int seed, int seq) {
        rng = new PcgSetseqState.PcgSetseqState8((byte)seed, (byte)seq);
        Pcg.setseq_8_srandom(rng, rng.state, rng.inc);
    }

    @Override
    public void setState(Number st) {
        rng.state = st.byteValue();
    }

    @Override
    public Number getState() {
        return rng.state;
    }

    @Override
    public void step() {
        Pcg.setseq_8_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.setseq_8_advance(rng, delta);
    }

    @Override
    public byte nextByte() {
        return Pcg.setseq_8_rxs_m_xs_8_random(rng);
    }

    @Override
    public int nextByte(int bound) {
        if(Pcg.checkOutBound8(bound)) return nextByte();
        return Byte.toUnsignedInt(Pcg.setseq_8_rxs_m_xs_8_bounded(rng, (byte)bound));
    }
}
