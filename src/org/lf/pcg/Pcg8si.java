package org.lf.pcg;

public class Pcg8si implements Random.Random8 {

    private final PcgState.PcgState8 rng;

    public Pcg8si() {
        this((int)System.currentTimeMillis());
    }
    public Pcg8si(int seed) {
        rng = new PcgState.PcgState8((byte)seed);
        Pcg.oneseq_8_srandom(rng, rng.state);
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
        Pcg.oneseq_8_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.oneseq_8_advance(rng, delta);
    }

    @Override
    public byte nextByte() {
        return Pcg.oneseq_8_rxs_m_xs_8_random(rng);
    }

    @Override
    public int nextByte(int bound) {
        if(Pcg.checkOutBound8(bound)) return nextByte();
        return Byte.toUnsignedInt(Pcg.oneseq_8_rxs_m_xs_8_bounded(rng, (byte)bound));
    }
}
