
#include "org_lf_pcg_Pcg.h"
#include "pcg_variants.h"
#include "pcg-advance-8.c"
#include "pcg-advance-16.c"
#include "pcg-advance-32.c"
#include "pcg-advance-64.c"

/* Some function to get value fast */

/*
 * Get state from any state8 object
 */
uint8_t get_state_8_state(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "B");
    return (uint8_t)((*env).GetByteField(obj, f_state));
}

/*
 * Get inc from setseq state8 object
 */
uint8_t get_state_8_inc(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "B");
    return (uint8_t)((*env).GetByteField(obj, f_inc));
}

/*
 * Get state from any state16 object
 */
uint16_t get_state_16_state(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "S");
    return (uint16_t)((*env).GetShortField(obj, f_state));
}

/*
 * Get inc from setseq state16 object
 */
uint16_t get_state_16_inc(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "S");
    return (uint16_t)((*env).GetShortField(obj, f_inc));
}

/*
 * Get state from any state32 object
 */
uint32_t get_state_32_state(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "I");
    return (uint32_t)((*env).GetIntField(obj, f_state));
}

/*
 * Get inc from setseq state32 object
 */
uint32_t get_state_32_inc(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "I");
    return (uint32_t)((*env).GetIntField(obj, f_inc));
}

/*
 * Get state from any state64 object
 */
uint64_t get_state_64_state(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "J");
    return (uint64_t)((*env).GetLongField(obj, f_state));
}

/*
 * Get inc from setseq state64 object
 */
uint64_t get_state_64_inc(JNIEnv *env, jobject obj) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "J");
    return (uint64_t)((*env).GetLongField(obj, f_inc));
}

/*
 * Set state to any state8 object
 */
void set_state_8_state(JNIEnv *env, jobject obj, uint8_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "B");
    (*env).SetByteField(obj, f_state, (jbyte)v);
}

/*
 * Set int to setseq state8 object
 */
void set_state_8_inc(JNIEnv *env, jobject obj, uint8_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "B");
    (*env).SetByteField(obj, f_inc, (jbyte)v);
}

/*
 * Set state to any state16 object
 */
void set_state_16_state(JNIEnv *env, jobject obj, uint16_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "S");
    (*env).SetShortField(obj, f_state, (jshort)v);
}

/*
 * Set int to setseq state16 object
 */
void set_state_16_inc(JNIEnv *env, jobject obj, uint16_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "S");
    (*env).SetShortField(obj, f_inc, (jshort)v);
}

/*
 * Set state to any state32 object
 */
void set_state_32_state(JNIEnv *env, jobject obj, uint32_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "I");
    (*env).SetIntField(obj, f_state, (jint)v);
}

/*
 * Set int to setseq state32 object
 */
void set_state_32_inc(JNIEnv *env, jobject obj, uint32_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "I");
    (*env).SetIntField(obj, f_inc, (jint)v);
}

/*
 * Set state to any state64 object
 */
void set_state_64_state(JNIEnv *env, jobject obj, uint64_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_state = (*env).GetFieldID(cls, "state", "J");
    (*env).SetLongField(obj, f_state, (jlong)v);
}

/*
 * Set int to setseq state64 object
 */
void set_state_64_inc(JNIEnv *env, jobject obj, uint64_t v) {
    jclass cls = (*env).GetObjectClass(obj);
    jfieldID f_inc = (*env).GetFieldID(cls, "inc", "J");
    (*env).SetLongField(obj, f_inc, (jlong)v);
}

/* Function of JNI needed */

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultMultiplier8
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_org_lf_pcg_Pcg_getDefaultMultiplier8(JNIEnv *env, jclass cls) {
    return (jbyte)PCG_DEFAULT_MULTIPLIER_8;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultMultiplier16
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_org_lf_pcg_Pcg_getDefaultMultiplier16(JNIEnv *env, jclass cls) {
    return (jshort)PCG_DEFAULT_MULTIPLIER_16;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultMultiplier32
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lf_pcg_Pcg_getDefaultMultiplier32(JNIEnv *env, jclass cls) {
    return (jint)PCG_DEFAULT_MULTIPLIER_32;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultMultiplier64
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_lf_pcg_Pcg_getDefaultMultiplier64(JNIEnv *env, jclass cls) {
    return (jlong)PCG_DEFAULT_MULTIPLIER_64;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultIncrement8
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_org_lf_pcg_Pcg_getDefaultIncrement8(JNIEnv *env, jclass cls) {
    return (jbyte)PCG_DEFAULT_INCREMENT_8;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultIncrement16
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_org_lf_pcg_Pcg_getDefaultIncrement16(JNIEnv *env, jclass cls) {
    return (jshort)PCG_DEFAULT_INCREMENT_16;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultIncrement32
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_lf_pcg_Pcg_getDefaultIncrement32(JNIEnv *env, jclass cls) {
    return (jint)PCG_DEFAULT_INCREMENT_32;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    getDefaultIncrement64
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_lf_pcg_Pcg_getDefaultIncrement64(JNIEnv *env, jclass cls) {
    return (jlong)PCG_DEFAULT_INCREMENT_64;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_8_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;B)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_18_1srandom(JNIEnv *env, jclass cls, jobject obj, jbyte init_state) {
    struct pcg_state_8 rng;
    pcg_oneseq_8_srandom_r(&rng, (uint8_t)init_state);
    set_state_8_state(env, obj, rng.state);
}


/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_8_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;B)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_18_1srandom(JNIEnv *env, jclass cls, jobject obj, jbyte init_state) {
    struct pcg_state_8 rng;
    pcg_mcg_8_srandom_r(&rng, (uint8_t)init_state);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_8_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;B)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_18_1srandom(JNIEnv *env, jclass cls, jobject obj, jbyte init_state) {
    struct pcg_state_8 rng;
    pcg_unique_8_srandom_r(&rng, (uint8_t)init_state);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_8_srandom
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState8;BB)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_18_1srandom(JNIEnv *env, jclass cls, jobject obj, jbyte init_state, jbyte init_seq) {
    struct pcg_state_setseq_8 rng;
    pcg_setseq_8_srandom_r(&rng, (uint8_t)init_state, (uint8_t)init_seq);
    set_state_8_state(env, obj, rng.state);
    set_state_8_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;S)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1srandom(JNIEnv *env, jclass cls, jobject obj, jshort init_state) {
    struct pcg_state_16 rng;
    pcg_oneseq_16_srandom_r(&rng, (uint16_t)init_state);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;S)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1srandom(JNIEnv *env, jclass cls, jobject obj, jshort init_state) {
    struct pcg_state_16 rng;
    pcg_mcg_16_srandom_r(&rng, (uint16_t)init_state);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;S)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_116_1srandom(JNIEnv *env, jclass cls, jobject obj, jshort init_state) {
    struct pcg_state_16 rng;
    pcg_unique_16_srandom_r(&rng, (uint16_t)init_state);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_srandom
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;SS)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1srandom(JNIEnv *env, jclass cls, jobject obj, jshort init_state, jshort init_seq) {
    struct pcg_state_setseq_16 rng;
    pcg_setseq_16_srandom_r(&rng, (uint16_t)init_state, (uint16_t)init_seq);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1srandom(JNIEnv *env, jclass cls, jobject obj, jint init_state) {
    struct pcg_state_32 rng;
    pcg_oneseq_32_srandom_r(&rng, (uint32_t)init_state);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1srandom(JNIEnv *env, jclass cls, jobject obj, jint init_state) {
    struct pcg_state_32 rng;
    pcg_mcg_32_srandom_r(&rng, (uint32_t)init_state);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_132_1srandom(JNIEnv *env, jclass cls, jobject obj, jint init_state) {
    struct pcg_state_32 rng;
    pcg_unique_32_srandom_r(&rng, (uint32_t)init_state);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_srandom
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;II)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1srandom(JNIEnv *env, jclass cls, jobject obj, jint init_state, jint init_seq) {
    struct pcg_state_setseq_32 rng;
    pcg_setseq_32_srandom_r(&rng, (uint32_t)init_state, (uint32_t)init_seq);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1srandom(JNIEnv *env, jclass cls, jobject obj, jlong init_state) {
    struct pcg_state_64 rng;
    pcg_oneseq_64_srandom_r(&rng, (uint64_t)init_state);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1srandom(JNIEnv *env, jclass cls, jobject obj, jlong init_state) {
    struct pcg_state_64 rng;
    pcg_mcg_64_srandom_r(&rng, (uint64_t)init_state);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_srandom
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_164_1srandom(JNIEnv *env, jclass cls, jobject obj, jlong init_state) {
    struct pcg_state_64 rng;
    pcg_unique_64_srandom_r(&rng, (uint64_t)init_state);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_srandom
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;JJ)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1srandom(JNIEnv *env, jclass cls, jobject obj, jlong init_state, jlong init_seq) {
    struct pcg_state_setseq_64 rng;
    pcg_setseq_64_srandom_r(&rng, (uint64_t)init_state, (uint64_t)init_seq);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_8_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_18_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_oneseq_8_step_r(&rng);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_8_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_18_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_mcg_8_step_r(&rng);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_8_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_18_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_unique_8_step_r(&rng);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_8_step
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState8;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_18_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_8 rng;
    rng.state = get_state_8_state(env, obj);
    rng.inc = get_state_8_inc(env, obj);
    pcg_setseq_8_step_r(&rng);
    set_state_8_state(env, obj, rng.state);
    set_state_8_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_oneseq_16_step_r(&rng);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_mcg_16_step_r(&rng);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_116_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_unique_16_step_r(&rng);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_step
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    pcg_setseq_16_step_r(&rng);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_oneseq_32_step_r(&rng);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_mcg_32_step_r(&rng);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_132_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_unique_32_step_r(&rng);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_step
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    pcg_setseq_32_step_r(&rng);
    set_state_32_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_oneseq_64_step_r(&rng);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_mcg_64_step_r(&rng);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_step
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_164_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_unique_64_step_r(&rng);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_step
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1step(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    pcg_setseq_64_step_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_8_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_18_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_oneseq_8_advance_r(&rng, delta);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_8_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_18_1advance
(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_mcg_8_advance_r(&rng, delta);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_8_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_18_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    pcg_unique_8_advance_r(&rng, delta);
    set_state_8_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_8_advance
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState8;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_18_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_setseq_8 rng;
    rng.state = get_state_8_state(env, obj);
    rng.inc = get_state_8_inc(env, obj);
    pcg_setseq_8_advance_r(&rng, delta);
    set_state_8_state(env, obj, rng.state);
    set_state_8_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_oneseq_16_advance_r(&rng, delta);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_mcg_16_advance_r(&rng, delta);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_116_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    pcg_unique_16_advance_r(&rng, delta);
    set_state_16_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_advance
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    pcg_setseq_16_advance_r(&rng, delta);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_oneseq_32_advance_r(&rng, delta);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_mcg_32_advance_r(&rng, delta);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_132_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    pcg_unique_32_advance_r(&rng, delta);
    set_state_32_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_advance
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    pcg_setseq_32_advance_r(&rng, delta);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_oneseq_64_advance_r(&rng, delta);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_advance
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_mcg_64_advance_r(&rng, delta);
    set_state_64_state(env, obj, rng.state);
}

/*
* Class:     org_lf_pcg_Pcg
* Method:    unique_64_advance
* Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)V
*/
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_unique_164_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    pcg_unique_64_advance_r(&rng, delta);
    set_state_64_state(env, obj, rng.state);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_advance
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;I)V
 */
JNIEXPORT void JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1advance(JNIEnv *env, jclass cls, jobject obj, jint delta) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    pcg_setseq_64_advance_r(&rng, delta);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_xsh_rs_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1xsh_1rs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_oneseq_16_xsh_rs_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_xsh_rs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1xsh_1rs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_oneseq_16_xsh_rs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_xsh_rs_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1xsh_1rs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_oneseq_32_xsh_rs_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_xsh_rs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1xsh_1rs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_oneseq_32_xsh_rs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsh_rs_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsh_1rs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsh_rs_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsh_rs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsh_1rs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsh_rs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_xsh_rs_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_unique_116_1xsh_1rs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_unique_16_xsh_rs_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_xsh_rs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_unique_116_1xsh_1rs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_unique_16_xsh_rs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_xsh_rs_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_132_1xsh_1rs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_unique_32_xsh_rs_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_xsh_rs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_132_1xsh_1rs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_unique_32_xsh_rs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsh_rs_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsh_1rs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsh_rs_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsh_rs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsh_1rs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsh_rs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_xsh_rs_8_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1xsh_1rs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint8_t ret = pcg_setseq_16_xsh_rs_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_xsh_rs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1xsh_1rs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint8_t ret = pcg_setseq_16_xsh_rs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_xsh_rs_16_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1xsh_1rs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint16_t ret = pcg_setseq_32_xsh_rs_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_xsh_rs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1xsh_1rs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint16_t ret = pcg_setseq_32_xsh_rs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsh_rs_32_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsh_1rs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsh_rs_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsh_rs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsh_1rs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsh_rs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_xsh_rs_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1xsh_1rs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_mcg_16_xsh_rs_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_xsh_rs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1xsh_1rs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_mcg_16_xsh_rs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_xsh_rs_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1xsh_1rs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_mcg_32_xsh_rs_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_xsh_rs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1xsh_1rs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_mcg_32_xsh_rs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsh_rs_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsh_1rs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsh_rs_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsh_rs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsh_1rs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsh_rs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_xsh_rr_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1xsh_1rr_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_oneseq_16_xsh_rr_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_xsh_rr_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1xsh_1rr_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_oneseq_16_xsh_rr_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_xsh_rr_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1xsh_1rr_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_oneseq_32_xsh_rr_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_xsh_rr_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1xsh_1rr_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_oneseq_32_xsh_rr_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsh_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsh_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsh_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsh_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsh_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsh_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_xsh_rr_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_unique_116_1xsh_1rr_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_unique_16_xsh_rr_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_xsh_rr_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_unique_116_1xsh_1rr_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_unique_16_xsh_rr_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_xsh_rr_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_132_1xsh_1rr_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_unique_32_xsh_rr_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_xsh_rr_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_132_1xsh_1rr_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_unique_32_xsh_rr_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsh_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsh_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsh_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsh_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsh_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsh_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_xsh_rr_8_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1xsh_1rr_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint8_t ret = pcg_setseq_16_xsh_rr_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_xsh_rr_8_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1xsh_1rr_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint8_t ret = pcg_setseq_16_xsh_rr_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_xsh_rr_16_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1xsh_1rr_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint16_t ret = pcg_setseq_32_xsh_rr_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_xsh_rr_16_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1xsh_1rr_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint16_t ret = pcg_setseq_32_xsh_rr_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsh_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsh_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsh_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsh_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsh_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsh_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_xsh_rr_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1xsh_1rr_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_mcg_16_xsh_rr_8_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_16_xsh_rr_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_mcg_116_1xsh_1rr_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint8_t ret = pcg_mcg_16_xsh_rr_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_xsh_rr_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1xsh_1rr_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_mcg_32_xsh_rr_16_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_32_xsh_rr_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_mcg_132_1xsh_1rr_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint16_t ret = pcg_mcg_32_xsh_rr_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsh_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsh_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsh_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsh_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsh_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsh_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_8_rxs_m_xs_8_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_18_1rxs_1m_1xs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    uint8_t ret = pcg_oneseq_8_rxs_m_xs_8_random_r(&rng);
    set_state_8_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_8_rxs_m_xs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState8;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_oneseq_18_1rxs_1m_1xs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_8 rng;
    rng.state = get_state_8_state(env, obj);
    uint8_t ret = pcg_oneseq_8_rxs_m_xs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_8_state(env, obj, rng.state);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_rxs_m_xs_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1rxs_1m_1xs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint16_t ret = pcg_oneseq_16_rxs_m_xs_16_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_16_rxs_m_xs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_oneseq_116_1rxs_1m_1xs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint16_t ret = pcg_oneseq_16_rxs_m_xs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_rxs_m_xs_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1rxs_1m_1xs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint32_t ret = pcg_oneseq_32_rxs_m_xs_32_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_32_rxs_m_xs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_132_1rxs_1m_1xs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint32_t ret = pcg_oneseq_32_rxs_m_xs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_rxs_m_xs_64_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1rxs_1m_1xs_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_oneseq_64_rxs_m_xs_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_rxs_m_xs_64_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1rxs_1m_1xs_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_oneseq_64_rxs_m_xs_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_rxs_m_xs_16_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_116_1rxs_1m_1xs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint16_t ret = pcg_unique_16_rxs_m_xs_16_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_16_rxs_m_xs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState16;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_unique_116_1rxs_1m_1xs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_16 rng;
    rng.state = get_state_16_state(env, obj);
    uint16_t ret = pcg_unique_16_rxs_m_xs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_16_state(env, obj, rng.state);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_rxs_m_xs_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_132_1rxs_1m_1xs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint32_t ret = pcg_unique_32_rxs_m_xs_32_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_32_rxs_m_xs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState32;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_132_1rxs_1m_1xs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_32 rng;
    rng.state = get_state_32_state(env, obj);
    uint32_t ret = pcg_unique_32_rxs_m_xs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_32_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_rxs_m_xs_64_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_unique_164_1rxs_1m_1xs_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_unique_64_rxs_m_xs_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_rxs_m_xs_64_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_unique_164_1rxs_1m_1xs_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_unique_64_rxs_m_xs_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_8_rxs_m_xs_8_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState8;)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_18_1rxs_1m_1xs_18_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_8 rng;
    rng.state = get_state_8_state(env, obj);
    rng.inc = get_state_8_inc(env, obj);
    uint8_t ret = pcg_setseq_8_rxs_m_xs_8_random_r(&rng);
    set_state_8_state(env, obj, rng.state);
    set_state_8_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_8_rxs_m_xs_8_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState8;B)B
 */
JNIEXPORT jbyte JNICALL
Java_org_lf_pcg_Pcg_setseq_18_1rxs_1m_1xs_18_1bounded(JNIEnv *env, jclass cls, jobject obj, jbyte bound) {
    struct pcg_state_setseq_8 rng;
    rng.state = get_state_8_state(env, obj);
    rng.inc = get_state_8_inc(env, obj);
    uint8_t ret = pcg_setseq_8_rxs_m_xs_8_boundedrand_r(&rng, (uint8_t)bound);
    set_state_8_state(env, obj, rng.state);
    set_state_8_inc(env, obj, rng.inc);
    return (jbyte)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_rxs_m_xs_16_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1rxs_1m_1xs_116_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint16_t ret = pcg_setseq_16_rxs_m_xs_16_random_r(&rng);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_16_rxs_m_xs_16_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState16;S)S
 */
JNIEXPORT jshort JNICALL
Java_org_lf_pcg_Pcg_setseq_116_1rxs_1m_1xs_116_1bounded(JNIEnv *env, jclass cls, jobject obj, jshort bound) {
    struct pcg_state_setseq_16 rng;
    rng.state = get_state_16_state(env, obj);
    rng.inc = get_state_16_inc(env, obj);
    uint16_t ret = pcg_setseq_16_rxs_m_xs_16_boundedrand_r(&rng, (uint16_t)bound);
    set_state_16_state(env, obj, rng.state);
    set_state_16_inc(env, obj, rng.inc);
    return (jshort)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_rxs_m_xs_32_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1rxs_1m_1xs_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint32_t ret = pcg_setseq_32_rxs_m_xs_32_random_r(&rng);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_32_rxs_m_xs_32_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState32;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_132_1rxs_1m_1xs_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_setseq_32 rng;
    rng.state = get_state_32_state(env, obj);
    rng.inc = get_state_32_inc(env, obj);
    uint32_t ret = pcg_setseq_32_rxs_m_xs_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_32_state(env, obj, rng.state);
    set_state_32_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_rxs_m_xs_64_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1rxs_1m_1xs_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint64_t ret = pcg_setseq_64_rxs_m_xs_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_rxs_m_xs_64_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1rxs_1m_1xs_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint64_t ret = pcg_setseq_64_rxs_m_xs_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsl_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsl_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsl_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsl_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsl_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_oneseq_64_xsl_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsl_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsl_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsl_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsl_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsl_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_unique_64_xsl_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsl_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsl_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsl_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsl_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsl_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint32_t ret = pcg_setseq_64_xsl_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsl_rr_32_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsl_1rr_132_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsl_rr_32_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    mcg_64_xsl_rr_32_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;I)I
 */
JNIEXPORT jint JNICALL
Java_org_lf_pcg_Pcg_mcg_164_1xsl_1rr_132_1bounded(JNIEnv *env, jclass cls, jobject obj, jint bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint32_t ret = pcg_mcg_64_xsl_rr_32_boundedrand_r(&rng, (uint32_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jint)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsl_rr_rr_64_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsl_1rr_1rr_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_oneseq_64_xsl_rr_rr_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    oneseq_64_xsl_rr_rr_64_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_oneseq_164_1xsl_1rr_1rr_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_oneseq_64_xsl_rr_rr_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsl_rr_rr_64_random
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsl_1rr_1rr_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_unique_64_xsl_rr_rr_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    unique_64_xsl_rr_rr_64_bounded
 * Signature: (Lorg/lf/pcg/PcgState/PcgState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_unique_164_1xsl_1rr_1rr_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_64 rng;
    rng.state = get_state_64_state(env, obj);
    uint64_t ret = pcg_unique_64_xsl_rr_rr_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsl_rr_rr_64_random
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsl_1rr_1rr_164_1random(JNIEnv *env, jclass cls, jobject obj) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint64_t ret = pcg_setseq_64_xsl_rr_rr_64_random_r(&rng);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jlong)ret;
}

/*
 * Class:     org_lf_pcg_Pcg
 * Method:    setseq_64_xsl_rr_rr_64_bounded
 * Signature: (Lorg/lf/pcg/PcgSetseqState/PcgSetseqState64;J)J
 */
JNIEXPORT jlong JNICALL
Java_org_lf_pcg_Pcg_setseq_164_1xsl_1rr_1rr_164_1bounded(JNIEnv *env, jclass cls, jobject obj, jlong bound) {
    struct pcg_state_setseq_64 rng;
    rng.state = get_state_64_state(env, obj);
    rng.inc = get_state_64_inc(env, obj);
    uint64_t ret = pcg_setseq_64_xsl_rr_rr_64_boundedrand_r(&rng, (uint64_t)bound);
    set_state_64_state(env, obj, rng.state);
    set_state_64_inc(env, obj, rng.inc);
    return (jlong)ret;
}
