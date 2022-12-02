package org.lf.pcg;

import java.math.BigInteger;

public interface Random {

    /**
     * Set state of random.
     * @param st The state
     */
    void setState(Number st);

    /**
     * Get state of this random.
     * @return State of this random
     */
    Number getState();

    /**
     * Step to next value, similar to skip.
     */
    void step();

    /**
     * Advance move to value, it can forward like {@link #step()},
     *  also, it can pass negative value to go backward.
     * @param delta The move delta
     */
    void advance(int delta);

    /* boolean */

    /**
     * Get next random boolean.
     * @return Boolean {@code true} or {@code false}
     */
    default boolean nextBoolean() {
        return (nextByte() & 1) == 1;
    }

    /* byte */

    /**
     * Get next random byte.
     * @return Byte from -128 to 128(exclude)
     */
    byte nextByte();

    /**
     * Get next random byte with limit.
     * @param bound The max number(exclude)
     * @return Byte from 0 to {@code bound} up to 256
     */
    default int nextByte(int bound) {
        if(Pcg.checkOutBound8(bound)) return Byte.toUnsignedInt(nextByte());
        int threshold = -bound % bound;
        for(;;) {
            int r = Byte.toUnsignedInt(nextByte());
            if(r >= threshold)
                return r % bound;
        }
    }

    /**
     * Get next random byte with range.
     * @param min The min number(include)
     * @param max The max number(exclude)
     * @return Byte from {@code min} to {@code max}
     */
    default byte nextByte(int min, int max) {
        short x = (short)Math.min(max, Byte.MAX_VALUE + 1);
        short n = (short)Math.max(min, Byte.MIN_VALUE);
        int b = nextByte(x - n);
        return (byte)(b + n);
    }

    /* short */

    /**
     * Get next random short.
     * @return Short from -65536 to 65536(exclude)
     */
    short nextShort();

    /**
     * Get next random short with limit.
     * @param bound The max number(exclude)
     * @return Short from 0 to {@code bound} up to 65536
     */
    default int nextShort(int bound) {
        if(Pcg.checkOutBound16(bound)) return Short.toUnsignedInt(nextShort());
        int threshold = -bound % bound;
        for(;;) {
            int r = Short.toUnsignedInt(nextShort());
            if(r >= threshold)
                return r % bound;
        }
    }

    /**
     * Get next random short with range.
     * @param min The min number(include)
     * @param max The max number(exclude)
     * @return Short from {@code min} to {@code max}
     */
    default short nextShort(int min, int max) {
        int x = Math.min(max, Short.MAX_VALUE + 1);
        int n = Math.max(min, Short.MIN_VALUE);
        int b = nextShort(x - n);
        return (short)(b + n);
    }

    /* int */

    /**
     * Get next random int.
     * @return Integer from -2^31 to 2^31(exclude)
     */
    int nextInt();

    /**
     * Get next random int with limit.
     * @param bound The max number(exclude)
     * @return Integer from 0 to {@code bound} up to 2^32
     */
    default long nextInt(long bound) {
        if(Pcg.checkOutBound32(bound)) return nextInt();
        long threshold = -bound % bound;
        for(;;) {
            long r = Integer.toUnsignedLong(nextInt());
            if(r >= threshold)
                return r % bound;
        }
    }

    /**
     * Get next random int with range.
     * @param min The min number(include)
     * @param max The max number(exclude)
     * @return Integer from {@code min} to {@code max}
     */
    default int nextInt(int min, int max) {
        long x = Math.min(max, Integer.MAX_VALUE + 1L);
        long n = Math.max(min, (long)Integer.MIN_VALUE);
        long b = nextInt(x - n);
        return (int)(b + n);
    }

    /* long */

    /**
     * Get next random long.
     * @return Long from -2^63 to 2^64(exclude)
     */
    long nextLong();

    /**
     * Get next random long with limit.
     * @param bound The max number(exclude)
     * @return Long from 0 to {@code bound} up to 2^64
     */
    default BigInteger nextLong(BigInteger bound) {
        if(Pcg.checkOutBound64(bound)) return new BigInteger(Long.toUnsignedString(nextLong()));
        BigInteger threshold = bound.negate().mod(bound);
        for(;;) {
            BigInteger r = new BigInteger(Long.toUnsignedString(nextLong()));
            if(r.compareTo(threshold) >= 0)
                return r.remainder(bound);
        }
    }

    /**
     * Get next random long with range.
     * @param min The min number(include)
     * @param max The max number(exclude)
     * @return Long from {@code min} to {@code max}
     */
    default long nextLong(long min, long max) {
        BigInteger x = BigInteger.valueOf(max).min(BigInteger.valueOf(Long.MAX_VALUE).add(BigInteger.ONE));
        BigInteger n = BigInteger.valueOf(min).max(BigInteger.valueOf(Long.MIN_VALUE));
        BigInteger b = nextLong(x.subtract(n));
        return b.add(n).longValue();
    }

    /**
     * Get next random float.
     * @return Float in 0.0f to 1.0f(exclude)
     */
    default float nextFloat() {
        return Math.abs((float)(nextInt() * Math.pow(2, -32)));
    }

    /**
     * Get next random double.
     * @return Double in 0.0 to 1.0(exclude)
     */
    default double nextDouble() {
        return Math.abs(nextLong() * Math.pow(2, -64));
    }

    interface Random8 extends Random {

        @Override
        default short nextShort() {
            return (short)(((short)nextByte() << 8) | nextByte());
        }

        @Override
        default int nextInt() {
            return ((int)nextShort() << 16) | Short.toUnsignedInt(nextShort());
        }

        @Override
        default long nextLong() {
            return ((long)nextInt() << 32) | Integer.toUnsignedLong(nextInt());
        }

    }

    interface Random16 extends Random {

        @Override
        default byte nextByte() {
            return (byte)nextShort();
        }

        @Override
        default int nextInt() {
            return ((int)nextShort() << 16) | Short.toUnsignedInt(nextShort());
        }

        @Override
        default long nextLong() {
            return ((long)nextInt() << 32) | Integer.toUnsignedLong(nextInt());
        }
    }

    interface Random32 extends Random {

        @Override
        default byte nextByte() {
            return (byte)nextInt();
        }

        @Override
        default short nextShort() {
            return (short)nextInt();
        }

        @Override
        default long nextLong() {
            return ((long)nextInt() << 32) | Integer.toUnsignedLong(nextInt());
        }
    }

    interface Random64 extends Random {

        @Override
        default byte nextByte() {
            return (byte)nextLong();
        }

        @Override
        default short nextShort() {
            return (short)nextLong();
        }

        @Override
        default int nextInt() {
            return (int)nextLong();
        }
    }
}
