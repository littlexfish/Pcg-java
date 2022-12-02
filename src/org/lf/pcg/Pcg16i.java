package org.lf.pcg;

public class Pcg16i implements Random.Random16 {
    
    private final PcgSetseqState.PcgSetseqState16 rng;
    
    public Pcg16i() {
        this((int)System.currentTimeMillis(), Pcg.getDefaultIncrement16());
    }
    public Pcg16i(int seed) {
        this(seed, Pcg.getDefaultIncrement16());
    }
    public Pcg16i(int seed, int seq) {
        rng = new PcgSetseqState.PcgSetseqState16((short)seed, (short)seq);
        Pcg.setseq_16_srandom(rng, rng.state, rng.inc);
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
        Pcg.setseq_16_step(rng);
    }

    @Override
    public void advance(int delta) {
        Pcg.setseq_16_advance(rng, delta);
    }

    @Override
    public short nextShort() {
        return Pcg.setseq_16_rxs_m_xs_16_random(rng);
    }

    @Override
    public int nextShort(int bound) {
        if(Pcg.checkOutBound16(bound)) return nextShort();
        return Short.toUnsignedInt(Pcg.setseq_16_rxs_m_xs_16_bounded(rng, (short)bound));
    }
}
