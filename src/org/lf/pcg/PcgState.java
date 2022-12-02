package org.lf.pcg;

public abstract class PcgState {

    public static class PcgState8 extends PcgState {

        public byte state;

        public PcgState8(byte init) {
            state = init;
        }

        @Override
        public String toString() {
            return "PcgState8{" +
                    "state=" + state +
                    '}';
        }
    }

    public static class PcgState16 extends PcgState {

        public short state;

        public PcgState16(short init) {
            state = init;
        }

        @Override
        public String toString() {
            return "PcgState16{" +
                    "state=" + state +
                    '}';
        }
    }

    public static class PcgState32 extends PcgState {

        public int state;

        public PcgState32(int init) {
            state = init;
        }

        @Override
        public String toString() {
            return "PcgState32{" +
                    "state=" + state +
                    '}';
        }
    }

    public static class PcgState64 extends PcgState {

        public long state;

        public PcgState64(long init) {
            state = init;
        }

        @Override
        public String toString() {
            return "PcgState64{" +
                    "state=" + state +
                    '}';
        }
    }
}
