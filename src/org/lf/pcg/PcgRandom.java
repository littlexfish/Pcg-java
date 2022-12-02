package org.lf.pcg;

public class PcgRandom {

    private PcgRandom() {
        throw new UnsupportedOperationException("it's static class");
    }

    public static Random newSetseqXshRr32() {
        return new Pcg32();
    }
    public static Random newSetseqXshRr32(long seed) {
        return new Pcg32(seed);
    }
    public static Random newSetseqXshRr32(long seed, long seq) {
        return new Pcg32(seed, seq);
    }

    public static Random newOneseqXshRr32() {
        return new Pcg32s();
    }
    public static Random newOneseqXshRr32(long seed) {
        return new Pcg32s(seed);
    }

    public static Random newUniqueXshRr32() {
        return new Pcg32u();
    }
    public static Random newUniqueXshRr32(long seed) {
        return new Pcg32u(seed);
    }

    public static Random newMcgXshRs32() {
        return new Pcg32f();
    }
    public static Random newMcgXshRs32(long seed) {
        return new Pcg32f(seed);
    }

    public static Random newOneseqRxsMXs8() {
        return new Pcg8si();
    }
    public static Random newOneseqRxsMXs8(int seed) {
        return new Pcg8si(seed);
    }
    
    public static Random newOneseqRxsMXs16() {
        return new Pcg16si();
    }
    public static Random newOneseqRxsMXs16(int seed) {
        return new Pcg16si(seed);
    }
    
    public static Random newOneseqRxsMXs32() {
        return new Pcg32si();
    }
    public static Random newOneseqRxsMXs32(int seed) {
        return new Pcg32si(seed);
    }

    public static Random newOneseqRxsMXs64() {
        return new Pcg64si();
    }
    public static Random newOneseqRxsMXs64(int seed) {
        return new Pcg64si(seed);
    }

    public static Random newSetseqRxsMXs8() {
        return new Pcg8i();
    }
    public static Random newSetseqRxsMXs8(int seed) {
        return new Pcg8i(seed);
    }
    public static Random newSetseqRxsMXs8(int seed, int seq) {
        return new Pcg8i(seed, seq);
    }

    public static Random newSetseqRxsMXs16() {
        return new Pcg16i();
    }
    public static Random newSetseqRxsMXs16(int seed) {
        return new Pcg16i(seed);
    }
    public static Random newSetseqRxsMXs16(int seed, int seq) {
        return new Pcg16i(seed, seq);
    }

    public static Random newSetseqRxsMXs32() {
        return new Pcg32i();
    }
    public static Random newSetseqRxsMXs32(int seed) {
        return new Pcg32i(seed);
    }
    public static Random newSetseqRxsMXs32(int seed, int seq) {
        return new Pcg32i(seed, seq);
    }

    public static Random newSetseqRxsMXs64() {
        return new Pcg64i();
    }
    public static Random newSetseqRxsMXs64(long seed, long seq) {
        return new Pcg64i(seed, seq);
    }
    
}
