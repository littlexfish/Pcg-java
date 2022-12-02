package org.lf.pcg;

public class Pcg16si implements Random.Random16 {

    private final PcgState.PcgState16 rng;

    public Pcg16si() {
        this((int)System.currentTimeMillis());
    }
    public Pcg16si(int seed) {
        rng = new PcgState.PcgState16((short)seed);
        Pcg.oneseq_16_srandom(rng, rng.state);
    }

    @Override
    public void setState(Number st) {
        rng.state = st.shortValue();
    }

    @Override
    public Number getState() {
        return rng.state;
    }

    @Override
    public void step() {
        Pcg.oneseq_16_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.oneseq_16_advance(rng, delta);
    }

    @Override
    public short nextShort() {
        return Pcg.oneseq_16_rxs_m_xs_16_random(rng);
    }

    @Override
    public int nextShort(int bound) {
        if(Pcg.checkOutBound16(bound)) return nextShort();
        return Short.toUnsignedInt(Pcg.oneseq_16_rxs_m_xs_16_bounded(rng, (short)bound));
    }
}
