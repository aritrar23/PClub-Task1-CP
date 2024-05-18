# Voldemort's Castle
It is a dark time in the wizarding world.

Dumbledore has died, and Lord Voldemort's reign of terror continues. Voldemort devises an ingenious plan to catch his nemesis Harry Potter and finish him once and for all. Voldemort kidnaps Ginny and imprisons her in his castle. Harry, as expected, bravely arrives at the gates of his castle, with his inseparable friends Ron and Hermione, to rescue his love. Suddenly, the gates transform into prison bars and imprison Hermione and Ron, leaving only Harry free. The gates declare, in Voldemort’s blood-curdling snake-like hiss, “Harry Potter! Finally ready to face me alone, you coward? But before dueling me, let's see how much wits you have got!”

“Let me teach you some curses, little boy. My favourite ones are Avada Kedavra, Bombarda Maxima, Crucio, Draconifors, Expulso and Finite Incantatem. So that your small brain can understand these names, let’s call them A,B,C,D,E & F respectively. Each spell produces either a Red, Green or Blue jet of light. Now to confuse my opponent, I always use spells in pairs - like A & D, B & E, etc., and you can observe only the effect of the combination of these colours. Since you are really stupid, let me tell you Red + Green = Brown, Red + Blue = Purple, Blue + Green = Teal (bet you haven’t heard of teal, you dunderhead). Obviously Red + Red = Red, and so on.”

“In each test case ('n' total test cases), I will give you 6 such pairs of curses, and the colour their combination produces, and you have to tell me the individual colour of each curse A,B,C,D,E & F. Can you do it alone, without the mudblood Hermione’s help?” The gates echo Voldmort’s cruel high-pitched laughter.

“Also, you must know that each curse has a unique number called potency, denoting the power of this curse. All my favourite curses’ potencies are consecutive prime numbers, since I love primes. You must know that Red curse < Green curse < Blue curse for potency, and if there are 2 curses of same colour, then the lexicographically greater one has more potency. To make it simpler for your feather-brain, let's say if A is a Blue curse, and C is a Red curse, then A will have more potency, since Blue > Red in terms of potency. But if A & B both are Green curses, then B will have more potency."

"Now in each test case, I will give you the sum of the potencies of these 6 curses A, B, C, D, E & F (i.e., the sum of 6 consecutive primes). You have to find out these 6 primes, then tell which prime number corresponds to which curse, i.e., you have to give me the potency value of each curse A, B, C, D, E, & F. You have only 7 minutes for both these tasks (which means you should strive to complete the tasks in the minimum possible time complexity, especially the second one) !”

Help Harry solve this task as quickly as possible and rescue his friends Ron & Hermione, and especially his beloved Ginny.

## Input : 
The first line will contain the number of test cases n (1 <= n <= 100). The next 6 lines will contain a pair of curses (say AB) and the respective colour it produces (say Brown). (Note - Each curse letter will appear at least once in these 6 pairs, hence there will always exist a unique solution to the problem). So each line will be of the form (AB Brown). The 7th line contains a single integer s (1 <= s <= 10^6) - the sum of the 6 curses' potencies (i.e., the sum of 6 consecutive primes).

## Output: 
The output should consist of 6n lines (where n is the number of test cases). Each 6-line block should contain the curse alphabet (in alphabetical order) followed by its colour and potency, of the form (A Red 7). (see the example given below for more clarity)

## Example - 
### Input
1

AB Brown

AC Purple

BD Brown

DE Brown

EF Teal

AF Purple

112

### Output
A Red 11

B Green 17

C Blue 23

D Red 13

E Green 19

F Blue 29
