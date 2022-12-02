
# PCG Random Number Generation, Java Edition

This code provides an implementation of the PCG family of random number generators,
 which are fast, statistically excellent, and offer a number of useful features.

Full details of C addition can be found at [PCG-Random website](https://www.pcg-random.org/index.html)
 and [Github](https://github.com/imneme/pcg-c). This version of the code provides almost all
 functions in C addition you can use.

You can use two APIs as same as C addition, the low-level one which defines in class of Pcg,
 and higher-level one which was created with class. Generally, you should use high-level API.

## Examples

### high-level API

You can use class of `Pcg32` to create all type of number.

```java
Pcg32 random = new Pcg32();
```

Also, you can create the class by generation functions name(the number is 
 general output size of bit).

```java
Random random = PcgRandom.newSetseqXshRr32();
```

To get the random number, just call `nextXXX()`.

```java
byte randomByte = random.nextByte();

short randomShort = random.nextShort();

int randomInt = random.nextInt();

long randomLong = random.nextLong();
```

Beware of `float` type and `double` type. They will return the number between 0 and 1(exclusive) like `Math.random()`

```java
float randomFloat = random.nextFloat(); // 0.0f - 1.0f

double randomDouble = random.nextDouble(); // 0.0 - 1.0
```

If you want to roll back to previous checkpoint, use `getState()` to get state of the random, 
 and then just call `setState(Number)` to roll back.

```java
random.nextInt(); // 63503998
Number state = random.getState(); // get state
random.nextInt(); // 70552339
random.setState(state); // set state
random.nextInt(); // 70552339
```

### low-level API

You can create an object of any state like `PcgState.PcgState8`, than put it into any generation functions
 in `Pcg`.

Beware that you should always initial the state before generate the number.

```java
PcgState.PcgState8 ps = new PcgState.PcgState8((byte)0);
Pcg.oneseq_8_srandom(ps, 63503998); // generate the state at first

byte randomByte = Pcg.oneseq_8_rxs_m_xs_8_random(ps); // get next byte
```

Step over with `Pcg.XXX_step()`.

```java
Pcg.mcg_8_step(ps);
```

Of course, you can roll back easily.

```java
byte state = ps.state; // get the state
Pcg.unique_8_step(ps); // step the state
ps.state = state; // roll back
```

## Directory structure

The directories are arranged as follows:

- `native` -- contains native source file that jni needed
- `src` -- contains source of Java addition
- `sample` -- sample code, re-write from C addition to Java addition

## 128-bit Math

There's no 128-bit math in java, so I did not create the function for that,
 I think 64-bit(long) is enough.

