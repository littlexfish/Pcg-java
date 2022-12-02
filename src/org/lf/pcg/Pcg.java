package org.lf.pcg;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.nio.file.*;

@SuppressWarnings("unused")
public class Pcg {

    static {
        // load native library
        try {
            loadNative("Pcg");
        }
        catch(IOException e) {
            e.printStackTrace();
        }
    }

    private static void loadNative(String lib) throws IOException {
        try {
            System.loadLibrary(lib);
        }
        catch(UnsatisfiedLinkError e) {
            String os = System.getProperty("os.name").toLowerCase();
            if(os.contains("mac"))
                loadOutNative("lib" + lib + ".dylib");
            else if(os.contains("win"))
                loadOutNative(lib + ".dll");
            else if(os.contains("nux"))
                loadOutNative("lib" + lib + ".so");
        }
    }

    private static void loadOutNative(String fullName) throws IOException {
        String tempDir = System.getProperty("java.io.tmpdir");
        File dir = new File(tempDir, String.valueOf(System.nanoTime()));
        if(!dir.exists()) {
            if (!dir.mkdir())
                throw new IOException("Failed to create temp directory " + dir.getName());
            dir.deleteOnExit();
        }
        File file = new File(dir, fullName);
        InputStream res = Pcg.class.getResourceAsStream("/org/lf/pcg/jni/" + fullName);
        if(res == null) {
            throw new FileNotFoundException("resource file not found");
        }
        Files.copy(res, file.toPath());
        res.close();

        try {
            System.load(file.getAbsolutePath());
        }
        finally {
            if (isPosixCompliant()) {
                file.delete();
            }
            else {
                file.deleteOnExit();
            }
        }
    }

    private static boolean isPosixCompliant() {
        try {
            return FileSystems.getDefault().supportedFileAttributeViews().contains("posix");
        }
        catch(FileSystemNotFoundException | ProviderNotFoundException | SecurityException e) {
            return false;
        }
    }

    /**
     * Check the number not negative
     */
    private static boolean checkNoNeg(Number n) {
        return n.longValue() < 0;
    }

    static boolean checkOutBound8(int bound) {
        return checkNoNeg(bound) || bound > (int)Byte.MAX_VALUE - Byte.MIN_VALUE + 1;
    }
    static boolean checkOutBound16(int bound) {
        return checkNoNeg(bound) || bound > (int)Short.MAX_VALUE - Short.MIN_VALUE + 1;
    }
    static boolean checkOutBound32(long bound) {
        return checkNoNeg(bound) || bound > (long)Integer.MAX_VALUE - Integer.MIN_VALUE + 1;
    }
    static boolean checkOutBound64(BigInteger bound) {
        return checkNoNeg(bound) || bound.compareTo(BigInteger.valueOf(Long.MAX_VALUE).subtract(BigInteger.valueOf(Long.MIN_VALUE + 1))) > 0;
    }

    /*  native function  */

    // multiplier

    /**
     * Get byte type default pcg multiplier
     */
    public static native byte getDefaultMultiplier8();

    /**
     * Get short type default pcg multiplier
     */
    public static native short getDefaultMultiplier16();

    /**
     * Get int type default pcg multiplier
     */
    public static native int getDefaultMultiplier32();

    /**
     * Get long type default pcg multiplier
     */
    public static native long getDefaultMultiplier64();


    // increment

    /**
     * Get byte type default pcg increment
     */
    public static native byte getDefaultIncrement8();

    /**
     * Get short type default pcg increment
     */
    public static native short getDefaultIncrement16();

    /**
     * Get int type default pcg increment
     */
    public static native int getDefaultIncrement32();

    /**
     * Get long type default pcg increment
     */
    public static native long getDefaultIncrement64();


    /* srandom */

    // 8

    /**
     * Initial byte type random state with init state using oneseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void oneseq_8_srandom(PcgState.PcgState8 rng, byte initState);

    /**
     * Initial byte type random state with init state using mcg
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void mcg_8_srandom(PcgState.PcgState8 rng, byte initState);

    /**
     * Initial byte type random state with init state using unique
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void unique_8_srandom(PcgState.PcgState8 rng, byte initState);

    /**
     * Initial byte type random state with init state using setseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void setseq_8_srandom(PcgSetseqState.PcgSetseqState8 rng, byte initState, byte initSeq);


    // 16

    /**
     * Initial short type random state with init state using oneseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void oneseq_16_srandom(PcgState.PcgState16 rng, short initState);

    /**
     * Initial short type random state with init state using mcg
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void mcg_16_srandom(PcgState.PcgState16 rng, short initState);

    /**
     * Initial short type random state with init state using unique
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void unique_16_srandom(PcgState.PcgState16 rng, short initState);

    /**
     * Initial short type random state with init state using setseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void setseq_16_srandom(PcgSetseqState.PcgSetseqState16 rng, short initState, short initSeq);


    // 32

    /**
     * Initial int type random state with init state using oneseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void oneseq_32_srandom(PcgState.PcgState32 rng, int initState);

    /**
     * Initial int type random state with init state using mcg
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void mcg_32_srandom(PcgState.PcgState32 rng, int initState);

    /**
     * Initial int type random state with init state using unique
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void unique_32_srandom(PcgState.PcgState32 rng, int initState);

    /**
     * Initial int type random state with init state using setseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void setseq_32_srandom(PcgSetseqState.PcgSetseqState32 rng, int initState, int initSeq);


    // 64

    /**
     * Initial long type random state with init state using oneseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void oneseq_64_srandom(PcgState.PcgState64 rng, long initState);

    /**
     * Initial long type random state with init state using setseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void mcg_64_srandom(PcgState.PcgState64 rng, long initState);

    /**
     * Initial long type random state with init state using unique
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void unique_64_srandom(PcgState.PcgState64 rng, long initState);

    /**
     * Initial long type random state with init state using setseq
     * @param rng The state store into
     * @param initState The initial state
     */
    public static native void setseq_64_srandom(PcgSetseqState.PcgSetseqState64 rng, long initState, long initSeq);

    /* step */

    // 8

    /**
     * Step the byte type random state using oneseq
     * @param rng The state store into
     */
    public static native void oneseq_8_step(PcgState.PcgState8 rng);

    /**
     * Step the byte type random state using mcg
     * @param rng The state store into
     */
    public static native void mcg_8_step(PcgState.PcgState8 rng);

    /**
     * Step the byte type random state using unique
     * @param rng The state store into
     */
    public static native void unique_8_step(PcgState.PcgState8 rng);

    /**
     * Step the byte type random state using setseq
     * @param rng The state store into
     */
    public static native void setseq_8_step(PcgSetseqState.PcgSetseqState8 rng);


    // 16

    /**
     * Step the short type random state using oneseq
     * @param rng The state store into
     */
    public static native void oneseq_16_step(PcgState.PcgState16 rng);

    /**
     * Step the short type random state using mcg
     * @param rng The state store into
     */
    public static native void mcg_16_step(PcgState.PcgState16 rng);

    /**
     * Step the short type random state using unique
     * @param rng The state store into
     */
    public static native void unique_16_step(PcgState.PcgState16 rng);

    /**
     * Step the short type random state using setseq
     * @param rng The state store into
     */
    public static native void setseq_16_step(PcgSetseqState.PcgSetseqState16 rng);


    // 32

    /**
     * Step the int type random state using oneseq
     * @param rng The state store into
     */
    public static native void oneseq_32_step(PcgState.PcgState32 rng);

    /**
     * Step the int type random state using mcg
     * @param rng The state store into
     */
    public static native void mcg_32_step(PcgState.PcgState32 rng);

    /**
     * Step the int type random state using unique
     * @param rng The state store into
     */
    public static native void unique_32_step(PcgState.PcgState32 rng);

    /**
     * Step the int type random state using setseq
     * @param rng The state store into
     */
    public static native void setseq_32_step(PcgSetseqState.PcgSetseqState32 rng);


    // 64

    /**
     * Step the long type random state using oneseq
     * @param rng The state store into
     */
    public static native void oneseq_64_step(PcgState.PcgState64 rng);

    /**
     * Step the long type random state using mcg
     * @param rng The state store into
     */
    public static native void mcg_64_step(PcgState.PcgState64 rng);

    /**
     * Step the long type random state using unique
     * @param rng The state store into
     */
    public static native void unique_64_step(PcgState.PcgState64 rng);

    /**
     * Step the long type random state using setseq
     * @param rng The state store into
     */
    public static native void setseq_64_step(PcgSetseqState.PcgSetseqState64 rng);


    /* advance */

    // 8

    /**
     * Advance the byte type random state using oneseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void oneseq_8_advance(PcgState.PcgState8 rng, int delta);

    /**
     * Advance the byte type random state using mcg
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void mcg_8_advance(PcgState.PcgState8 rng, int delta);

    /**
     * Advance the byte type random state using unique
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void unique_8_advance(PcgState.PcgState8 rng, int delta);

    /**
     * Advance the byte type random state using setseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void setseq_8_advance(PcgSetseqState.PcgSetseqState8 rng, int delta);


    // 16

    /**
     * Advance the short type random state using oneseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void oneseq_16_advance(PcgState.PcgState16 rng, int delta);

    /**
     * Advance the short type random state using mcg
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void mcg_16_advance(PcgState.PcgState16 rng, int delta);

    /**
     * Advance the short type random state using unique
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void unique_16_advance(PcgState.PcgState16 rng, int delta);

    /**
     * Advance the short type random state using setseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void setseq_16_advance(PcgSetseqState.PcgSetseqState16 rng, int delta);


    // 32

    /**
     * Advance the int type random state using oneseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void oneseq_32_advance(PcgState.PcgState32 rng, int delta);

    /**
     * Advance the int type random state using mcg
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void mcg_32_advance(PcgState.PcgState32 rng, int delta);

    /**
     * Advance the int type random state using unique
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void unique_32_advance(PcgState.PcgState32 rng, int delta);

    /**
     * Advance the int type random state using setseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void setseq_32_advance(PcgSetseqState.PcgSetseqState32 rng, int delta);


    // 64

    /**
     * Advance the long type random state using oneseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void oneseq_64_advance(PcgState.PcgState64 rng, int delta);

    /**
     * Advance the long type random state using mcg
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void mcg_64_advance(PcgState.PcgState64 rng, int delta);

    /**
     * Advance the long type random state using unique
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void unique_64_advance(PcgState.PcgState64 rng, int delta);

    /**
     * Advance the long type random state using setseq
     * @param rng The state store into
     * @param delta The delta use for advance
     */
    public static native void setseq_64_advance(PcgSetseqState.PcgSetseqState64 rng, int delta);


    /* XSH RS */

    // oneseq

    /**
     * Random a byte from short random state using xsh rs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte oneseq_16_xsh_rs_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte oneseq_16_xsh_rs_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short oneseq_32_xsh_rs_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short oneseq_32_xsh_rs_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int oneseq_64_xsh_rs_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int oneseq_64_xsh_rs_32_bounded(PcgState.PcgState64 rng, int bound);


    // unique

    /**
     * Random a byte from short random state using xsh rs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte unique_16_xsh_rs_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte unique_16_xsh_rs_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short unique_32_xsh_rs_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short unique_32_xsh_rs_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int unique_64_xsh_rs_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int unique_64_xsh_rs_32_bounded(PcgState.PcgState64 rng, int bound);


    // setseq

    /**
     * Random a byte from short random state using xsh rs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte setseq_16_xsh_rs_8_random(PcgSetseqState.PcgSetseqState16 rng);

    /**
     * Random a byte from short random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte setseq_16_xsh_rs_8_bounded(PcgSetseqState.PcgSetseqState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short setseq_32_xsh_rs_16_random(PcgSetseqState.PcgSetseqState32 rng);

    /**
     * Random a short from int random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short setseq_32_xsh_rs_16_bounded(PcgSetseqState.PcgSetseqState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int setseq_64_xsh_rs_32_random(PcgSetseqState.PcgSetseqState64 rng);

    /**
     * Random an int from long random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int setseq_64_xsh_rs_32_bounded(PcgSetseqState.PcgSetseqState64 rng, int bound);


    // mcg

    /**
     * Random a byte from short random state using xsh rs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte mcg_16_xsh_rs_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte mcg_16_xsh_rs_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short mcg_32_xsh_rs_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short mcg_32_xsh_rs_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int mcg_64_xsh_rs_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int mcg_64_xsh_rs_32_bounded(PcgState.PcgState64 rng, int bound);


    /* XSH RR */

    // oneseq

    /**
     * Random a byte from short random state using xsh rr
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte oneseq_16_xsh_rr_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte oneseq_16_xsh_rr_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rr
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short oneseq_32_xsh_rr_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short oneseq_32_xsh_rr_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int oneseq_64_xsh_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int oneseq_64_xsh_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    // unique

    /**
     * Random a byte from short random state using xsh rr
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte unique_16_xsh_rr_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte unique_16_xsh_rr_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rr
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short unique_32_xsh_rr_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short unique_32_xsh_rr_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int unique_64_xsh_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int unique_64_xsh_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    // setseq

    /**
     * Random a byte from short random state using xsh rr
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte setseq_16_xsh_rr_8_random(PcgSetseqState.PcgSetseqState16 rng);

    /**
     * Random a byte from short random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte setseq_16_xsh_rr_8_bounded(PcgSetseqState.PcgSetseqState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rr
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short setseq_32_xsh_rr_16_random(PcgSetseqState.PcgSetseqState32 rng);

    /**
     * Random a short from int random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short setseq_32_xsh_rr_16_bounded(PcgSetseqState.PcgSetseqState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int setseq_64_xsh_rr_32_random(PcgSetseqState.PcgSetseqState64 rng);

    /**
     * Random an int from long random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int setseq_64_xsh_rr_32_bounded(PcgSetseqState.PcgSetseqState64 rng, int bound);


    // mcg

    /**
     * Random a byte from short random state using xsh rr
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte mcg_16_xsh_rr_8_random(PcgState.PcgState16 rng);

    /**
     * Random a byte from short random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte mcg_16_xsh_rr_8_bounded(PcgState.PcgState16 rng, byte bound);

    /**
     * Random a short from int random state using xsh rr
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short mcg_32_xsh_rr_16_random(PcgState.PcgState32 rng);

    /**
     * Random a short from int random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short mcg_32_xsh_rr_16_bounded(PcgState.PcgState32 rng, short bound);

    /**
     * Random an int from long random state using xsh rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int mcg_64_xsh_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsh rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int mcg_64_xsh_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    /* RXS M XS (no mcg version) */

    // oneseq

    /**
     * Random a byte from byte random state using rxs m xs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte oneseq_8_rxs_m_xs_8_random(PcgState.PcgState8 rng);

    /**
     * Random a byte from byte random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte oneseq_8_rxs_m_xs_8_bounded(PcgState.PcgState8 rng, byte bound);

    /**
     * Random a short from short random state using rxs m xs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short oneseq_16_rxs_m_xs_16_random(PcgState.PcgState16 rng);

    /**
     * Random a short from short random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short oneseq_16_rxs_m_xs_16_bounded(PcgState.PcgState16 rng, short bound);

    /**
     * Random an int from int random state using rxs m xs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int oneseq_32_rxs_m_xs_32_random(PcgState.PcgState32 rng);

    /**
     * Random an int from int random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int oneseq_32_rxs_m_xs_32_bounded(PcgState.PcgState32 rng, int bound);

    /**
     * Random a long from short random state using rxs m xs
     * @param rng The state store into
     * @return A long from -2^63 to 2^63-1
     */
    public static native long oneseq_64_rxs_m_xs_64_random(PcgState.PcgState64 rng);

    /**
     * Random a long from long random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^64-1
     * @return A long from 0 to 2^64-1
     */
    public static native long oneseq_64_rxs_m_xs_64_bounded(PcgState.PcgState64 rng, long bound);


    // unique

    /**
     * Random a short from short random state using rxs m xs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short unique_16_rxs_m_xs_16_random(PcgState.PcgState16 rng);

    /**
     * Random a short from short random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short unique_16_rxs_m_xs_16_bounded(PcgState.PcgState16 rng, short bound);

    /**
     * Random an int from int random state using rxs m xs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int unique_32_rxs_m_xs_32_random(PcgState.PcgState32 rng);

    /**
     * Random an int from int random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int unique_32_rxs_m_xs_32_bounded(PcgState.PcgState32 rng, int bound);

    /**
     * Random a long from short random state using rxs m xs
     * @param rng The state store into
     * @return A long from -2^63 to 2^63-1
     */
    public static native long unique_64_rxs_m_xs_64_random(PcgState.PcgState64 rng);

    /**
     * Random a long from long random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^64-1
     * @return A long from 0 to 2^64-1
     */
    public static native long unique_64_rxs_m_xs_64_bounded(PcgState.PcgState64 rng, long bound);


    // setseq

    /**
     * Random a byte from byte random state using rxs m xs
     * @param rng The state store into
     * @return A byte from -2^7 to 2^7-1
     */
    public static native byte setseq_8_rxs_m_xs_8_random(PcgSetseqState.PcgSetseqState8 rng);

    /**
     * Random a byte from byte random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^8-1
     * @return A byte from 0 to 2^8-1
     */
    public static native byte setseq_8_rxs_m_xs_8_bounded(PcgSetseqState.PcgSetseqState8 rng, byte bound);

    /**
     * Random a short from short random state using rxs m xs
     * @param rng The state store into
     * @return A short from -2^15 to 2^15-1
     */
    public static native short setseq_16_rxs_m_xs_16_random(PcgSetseqState.PcgSetseqState16 rng);

    /**
     * Random a short from short random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^16-1
     * @return A short from 0 to 2^16-1
     */
    public static native short setseq_16_rxs_m_xs_16_bounded(PcgSetseqState.PcgSetseqState16 rng, short bound);

    /**
     * Random an int from int random state using rxs m xs
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int setseq_32_rxs_m_xs_32_random(PcgSetseqState.PcgSetseqState32 rng);

    /**
     * Random an int from int random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int setseq_32_rxs_m_xs_32_bounded(PcgSetseqState.PcgSetseqState32 rng, int bound);

    /**
     * Random a long from short random state using rxs m xs
     * @param rng The state store into
     * @return A long from -2^63 to 2^63-1
     */
    public static native long setseq_64_rxs_m_xs_64_random(PcgSetseqState.PcgSetseqState64 rng);

    /**
     * Random a long from long random state using rxs m xs with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^64-1
     * @return A long from 0 to 2^64-1
     */
    public static native long setseq_64_rxs_m_xs_64_bounded(PcgSetseqState.PcgSetseqState64 rng, long bound);


    /* XSL RR (only defined or "large" types) */

    // oneseq

    /**
     * Random an int from long random state using xsl rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int oneseq_64_xsl_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsl rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int oneseq_64_xsl_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    // unique

    /**
     * Random an int from long random state using xsl rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int unique_64_xsl_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsl rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int unique_64_xsl_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    // setseq

    /**
     * Random an int from long random state using xsl rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int setseq_64_xsl_rr_32_random(PcgSetseqState.PcgSetseqState64 rng);

    /**
     * Random an int from long random state using xsl rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int setseq_64_xsl_rr_32_bounded(PcgSetseqState.PcgSetseqState64 rng, int bound);


    // mcg

    /**
     * Random an int from long random state using xsl rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native int mcg_64_xsl_rr_32_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsl rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native int mcg_64_xsl_rr_32_bounded(PcgState.PcgState64 rng, int bound);


    /* XSL RR RR (only defined or "large" types) */

    // oneseq

    /**
     * Random an int from long random state using xsl rr rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native long oneseq_64_xsl_rr_rr_64_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsl rr rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native long oneseq_64_xsl_rr_rr_64_bounded(PcgState.PcgState64 rng, long bound);


    // unique

    /**
     * Random an int from long random state using xsl rr rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native long unique_64_xsl_rr_rr_64_random(PcgState.PcgState64 rng);

    /**
     * Random an int from long random state using xsl rr rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native long unique_64_xsl_rr_rr_64_bounded(PcgState.PcgState64 rng, long bound);


    // setseq

    /**
     * Random an int from long random state using xsl rr rr
     * @param rng The state store into
     * @return An int from -2^31 to 2^31-1
     */
    public static native long setseq_64_xsl_rr_rr_64_random(PcgSetseqState.PcgSetseqState64 rng);

    /**
     * Random an int from long random state using xsl rr rr with bound
     * @param rng The state store into
     * @param bound The limit for random, from 0 to 2^32-1
     * @return An int from 0 to 2^32-1
     */
    public static native long setseq_64_xsl_rr_rr_64_bounded(PcgSetseqState.PcgSetseqState64 rng, long bound);

}
