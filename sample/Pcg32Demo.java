import org.lf.pcg.Pcg32;

public class Pcg32Demo {

    public static void main(String[] args) {
        // Read command-line options

        int rounds = 5;
        boolean nonDeterministicSeed = false;

        if(args.length > 0 && args[0].equals("-r")) {
            nonDeterministicSeed = true;
        }
        if(args.length > 1) {
            try {
                rounds = Integer.parseInt(args[1]);
            }
            catch(NumberFormatException e) {
                e.printStackTrace();
            }
        }

        Pcg32 rng;

        if(nonDeterministicSeed) {
            rng = new Pcg32();
        }
        else {
            rng = new Pcg32(42, 54);
        }

        System.out.println("pcg32_random_r:\n" +
                "      -  result:      32-bit unsigned int (uint32_t)\n" +
                "      -  period:      2^64   (* 2^63 streams)\n" +
                "      -  state type:  pcg32_random_t\n" +
                "      -  output func: XSH-RR\n");

        for(int round = 1;round <= rounds;++round) {
            System.out.println("Round " + round + ":");

            /* Make some 32-bit numbers */
            System.out.print("  32bit:");
            for(int i = 0;i < 6;++i)
                System.out.printf(" 0x%08x", rng.nextInt());
            System.out.println();

            System.out.print("  Again:");
            rng.advance(-6);
            for(int i = 0;i < 6;++i)
                System.out.printf(" 0x%08x", rng.nextInt());
            System.out.println();

            /* Toss some coins */
            System.out.print("  Coins: ");
            for(int i = 0;i < 65;++i)
                System.out.print(rng.nextBoolean() ? 'H' : 'T');
            System.out.println();

            /* Roll some dice */
            System.out.print("  Rolls:");
            for(int i = 0;i < 33;++i)
                System.out.printf(" %d", rng.nextInt(6) + 1);
            System.out.println();

            /* Deal some cards */
            final int SUITS = 4;
            final int NUMBERS = 13;
            final int CARDS = SUITS * NUMBERS;
            char[] cards = new char[CARDS];
            for(int i = 0;i < CARDS;++i)
                cards[i] = (char)i;

            for(int i = CARDS;i > 1;--i) {
                int chosen = (int)rng.nextInt(i);
                char card = cards[chosen];
                cards[chosen] = cards[i - 1];
                cards[i - 1] = card;
            }

            System.out.print("  Cards:");
            final char[] number = {'A', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'T', 'J', 'Q', 'K'};
            final char[] suit = {'h', 'c', 'd', 's'};
            for(int i = 0;i < CARDS;++i) {
                System.out.printf(" %c%c", number[cards[i] / SUITS], suit[cards[i] % SUITS]);
                if((i + 1) % 22 == 0)
                    System.out.print("\n\t");
            }
            System.out.println();
            System.out.println();
        }

    }

}
