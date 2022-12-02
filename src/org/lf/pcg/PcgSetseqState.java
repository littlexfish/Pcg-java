package org.lf.pcg;

public abstract class PcgSetseqState {

    public static class PcgSetseqState8 extends PcgSetseqState {

        public byte state;
        public byte inc;

        public PcgSetseqState8(byte st, byte i) {
            state = st;
            inc = i;
        }
    }

    public static class PcgSetseqState16 extends PcgSetseqState {

        public short state;
        public short inc;

        public PcgSetseqState16(short st, short i) {
            state = st;
            inc = i;
        }
    }

    public static class PcgSetseqState32 extends PcgSetseqState {

        public int state;
        public int inc;

        public PcgSetseqState32(int st, int i) {
            state = st;
            inc = i;
        }
    }

    public static class PcgSetseqState64 extends PcgSetseqState {

        public long state;
        public long inc;

        public PcgSetseqState64(long st, long i) {
            state = st;
            inc = i;
        }
    }
}
