# Voldemort's Castle
Voldemort is upto his evils antics as usual. This time, he has kidnapped Ginny and is torturing her in his castle to lure Harry Potter to come and rescue her. Harry, always fond of playing the hero, bravely arrives at the gates of Voldemort’s castle, with his friends Ron and Hermione. Suddenly, the gates transform into prison bars and imprison Hermione and Ron, leaving only Harry free. The gates declare, in Voldemort’s blood-curdling high-pitched voice, “Harry Potter! In order to free Ron and Hermione, and rescue Ginny from my clutches, you have to solve the following riddle!”

“My favourite curses are Avada Kedavra, Bombarda Maxima, Crucio, Draconifors, Expulso and Finite Incantatem. So that your small brain can understand these names, let’s call them A,B,C,D,E & F respectively. Each spell produces either a Red, Green or Blue jet of light. Now to confuse my opponent, I always use spells in pairs - like A & D, B & E, etc., and you can observe only the effect of the combination of these colours. Since you are really stupid, let me tell you Red + Green = Brown, Red + Blue = Purple, Blue + Green = Teal (bet you haven’t heard of teal, you dunderhead). Obviously Red + Red = Red, and so on.”

“I will give you 6 such pairs of curses, and the colour their combination produces, and you have to tell me the individual colour of each curse A,B,C,D,E & F. Can you do it alone, without the mudblood Hermione’s help?” The gates echo Voldmort’s cruel high-pitched laughter.

“Also, you must know that each curse has a unique number called potency, denoting the power of this curse. All my favourite curses’ potencies are consecutive prime numbers, since I love primes. You must know that Red curse < Green curse < Blue curse for potency, and if there are 2 curses of same colour, then the lexicographically greater one has more potency. E.g - If A is a Blue curse, and C is a Red curse, then A will have more potency, since Blue > Red in terms of potency. But if A & B both are Green curses, then B will have more potency."

"Now I will give you the sum of the potencies of these 6 curses A, B, C, D, E & F (i.e., the sum of 6 consecutive primes). You have to find out these 6 primes, then tell which prime number corresponds to which curse, i.e., you have to give me the potency value of each curse A, B, C, D, E, & F. You have only 7 minutes for both these tasks (which means you should strive to complete the tasks in the minimum possible time complexity, especially the second one) !”

Help Harry solve this task as quickly as possible and rescue his friends Ron & Hermione, and especially his beloved Ginny.

### Input : 
Each of the first 6 lines contains a pair of curses (say AB) and the respective colour it produces (say Brown). So each line will be of the form (AB Brown). The 7th line contains a single integer s (1 <= s <= 10^6) - the sum of the 6 curses' potencies (i.e., the sum of 6 consecutive primes).

### Output: 
The output should consist of 6 lines. Each line should contain the curse alphabet (in alphabetical order) followed by its colour and potency (of the form A Red 7).

### Example - 
##### Input
AB Brown
AC Purple
BD Brown
DE Brown
EF Teal
AF Purple
112

##### Output
A Red 11
B Green 17
C Blue 23
D Red 13
E Green 19
F Blue 29