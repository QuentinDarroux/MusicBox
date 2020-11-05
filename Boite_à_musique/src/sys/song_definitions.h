

#define NUMBER_SONGS 5 /* The number of total songs that are on the board */

#define PSE 50000      /* The frequency of a pause in a song. Some songs have breaks and thus to deal with this we places an inaudible frequency */

/* Defining the neccessary octaves for the uploaded songs */

/*      Note Freq*/

#define DO7  2093
#define DOd7 2217
#define RE7  2349
#define REd7 2489
#define MI7  2637
#define FA7  2794
#define FAd7 2960
#define SOL7  3136
#define SOLd7 3322
#define LA7  3520
#define LAd7 3729
#define SI7  3951

/*----------------*/

#define DO6  1047
#define DOd6 1109
#define RE6  1175
#define REd6 1245
#define MI6  1319
#define FA6  1397
#define FAd6 1480
#define SOL6  1568
#define SOLd6 1661
#define LA6  1760
#define LAd6 1865
#define SI6  1976

/*----------------*/

/*4*/
#define DO4 	261
#define DOd4	277
#define RE4 	294
#define REd4	311
#define MI4 	330
#define FA4 	349
#define FAd4	370
#define SOL4	392
#define SOLd4	415
#define LA4 	440
#define LAd4	466
#define SI4 	493

/*----------------*/

/*5*/
#define DO5 	523
#define DOd5	554
#define RE5	    587
#define REd5	622
#define MI5	    659
#define FA5	    698
#define FAd5	739
#define SOL5	784
#define SOLd5	830
#define LA5	    880
#define LAd5	932
#define SI5	    987

/*----------------*/

/* Specific Harry Potter */
#define A 550
#define As 582
#define B 617
#define C 654
#define Cs 593
#define D 734
#define Ds 777
#define E 824
#define F 873
#define Fs 925
#define G 980
#define Gs 1003
#define A2 1100
#define A2s 1165
#define B2 1234
#define C3 1308
#define C3s 1385
#define D3 1555

/*----------------*/

#define L1 400
#define Lh 200
#define L1h 600
#define L2 800
#define L2h 1000

/*---------------*/

/* Each note has a certain duration which has to be mentioned. Depending on the song we have a different duration relative to the bpm  */

#define d1	714 
#define d2	1428 
#define d3	2857 

/*---------------*/

#define bs 195
#define bo 390
#define bp 780
#define bd 1560
#define bfull 3120


typedef struct{   /* This strucure represents a muscial note */
    
	int freq;  /* Frequency of the note */
	int duree; /* Duration of the note */
    
} Note; 

/* Song definitions of type Note */

Note au_clair_de_la_lune[45]= /* Containes the number of notes in the song */
{
 {SOL4,d1}, {SOL4,d1}, {SOL4,d1}, {LA4,d1}, {SI4,d2}, {LA4,d2}, {SOL4,d1}, {SI4,d1}, {LA4,d1}, {LA4,d1}, {SOL4,d3},
 {SOL4,d1}, {SOL4,d1}, {SOL4,d1}, {LA4,d1}, {SI4,d2}, {LA4,d2}, {SOL4,d1}, {SI4,d1}, {LA4,d1}, {LA4,d1}, {SOL4,d3},
 {LA4,d1}, {LA4,d1}, {LA4,d1}, {LA4,d1}, {MI4,d2}, {MI4,d2}, {LA4,d1}, {SOL4,d1}, {FAd4,d1}, {MI4,d1}, {RE4,d3},
 {SOL4,d1}, {SOL4,d1}, {SOL4,d1}, {LA4,d1}, {SI4,d2}, {LA4,d2}, {SOL4,d1}, {SI4,d1}, {LA4,d1}, {LA4,d1}, {SOL4,d3},
 {0,0}  /* Each song ends with {0, 0}, for the program to know when it will reach the end of the song */
};

Note berceuse[60]=
{
 {SOL4,bo}, {SOL4,bo}, {LAd4,(bp+bo)}, {SOL4,bo}, {SOL4,bp}, {LAd4,bp}, {PSE,bp}, {SOL4,bo}, {LAd4,bo},
 {REd5,bp}, {RE5,bp}, {DO5,bo}, {DO5,bp}, {LAd4,bp}, {FA4,bo}, {SOL4,bo}, {SOLd4,bp}, {FA4,bp}, {FA4,bo}, {SOL4,bo}, {SOLd4,bp}, {PSE,bp}, {FA4,bo}, {SOLd4,bo}, {RE5,bo}, {DO5,bo}, {LAd4,bp}, {RE5,bp}, {REd5,bd}, {SOL4,bo}, {SOL4,bo}, {REd5,bd}, {DO5,bo}, {SOLd4,bo}, {LAd4,bd}, {FA4,bo}, {SOL4,bo}, {LA4,bp}, {LAd4,bp}, {DO5,bp}, {LAd4,bd}, {SOL4,bo}, {SOL4,bo}, {REd5, bd}, {DO5,bo}, {SOLd4,bo}, {LAd4,bd}, {SOL4,bo}, {MI4,bo}, {SOLd4,bp}, {SOLd4,bp}, {SOL4,bp}, {SOL4,bp}, {PSE,bp},
 {0,0}
};

/* This is another way of defining the songs. When encoding the notes you can place the duration or the frequency directly into the structure */

Note harry_potter_theme[61]= {
 {SI4, 333},{MI5, 500},{SOL5, 166},{FAd5, 333},{MI5, 666},{SI5, 333},{LA5, 1000},{FAd5, 1000},{MI5, 500},{SOL5, 166},{FAd5, 333},{REd5, 666},{FA5, 333},{SI4, 1666},{SI4, 333},{MI5, 500},{SOL5, 166},{FAd5, 333},{MI5, 666},{SI5, 333},{RE6, 666},{DOd6, 333},{DO6, 666},{SOLd5, 333},{MI6, 500},{SI5, 166},{LAd5, 333},{LAd4, 666},{SOL5, 333},{MI5, 1666},{SOL5, 333},{SI5, 666},{SOL5, 333},{SI5, 666},{SOL5, 333},{DO6, 666},{SI5, 333},{LAd5, 666},{FAd5, 333},{SOL5, 500},{SI5, 166},{LAd5, 333},{LAd4, 666},{SI4, 333},{SI5, 1666},{SOL5, 333},{SI5, 666},{SOL5, 333},{SI5, 666},{SOL5, 333},{RE6, 666},{DOd6, 333},{DO6, 666},{SOLd5, 333},{DO6, 500},{SI5, 166},{LAd5, 333},{LAd4, 666},{SOL5, 333},{MI5, 1666},
 {0,0}
};

Note Bond[38] = {
    {DOd6, 187},{REd6, 93},{REd6, 93},{REd6, 187},{REd6, 375},{DOd6, 187},{DOd6, 187},{DOd6, 187},{DOd6, 187},{MI6, 93},{MI6, 93},{MI6, 187},{MI6, 375},{REd6, 187},{REd6, 187},{REd6, 187},{DOd6, 187},{REd6, 93},{REd6, 93},{REd6, 187},{REd6, 375},{DOd6, 187},{DOd6, 187},{DOd6, 187},{DOd6, 187},{MI6, 93},{MI6, 93},{MI6, 187},{MI6, 375},{REd6, 187},{RE6, 187},{DOd6, 187},{DOd7, 187},{DO7, 1125},{SOLd6, 187},{FAd6, 187},{SOLd6, 1125}, {0,0}
};

Note th_century_fox[62] = {
    {SI5, 107}, {PSE, 214},{SI5, 107},{SI5, 107}, {SI5, 856}, {PSE, 107},{DO6, 107}, {PSE, 53}, {SI5, 107}, {PSE, 53}, {DO6, 107},{PSE, 53},{SI5, 107},{PSE, 53},{DO6, 107},{PSE, 53},{SI5, 107},{PSE, 214},{SI5, 107},{SI5, 107},{SI5, 107},{PSE, 53},{SI5, 107},{PSE, 53},{SI5, 107},{PSE, 53},{SI5, 107}, {PSE, 53},{SI5, 107},{PSE, 53},{SI5, 107},{PSE, 53},{SI5, 107},{PSE, 53},{SOLd5, 107},{PSE, 53},{LA5, 107},{PSE, 53},{SI5, 107},{PSE, 214},{SI5, 107},{SI5, 107},{SI5, 856},{PSE, 428},{MI5, 214},{SOLd5, 214},{SI5, 214},{DOd6, 1712},{FAd5, 214},{LA5, 214},{DOd6, 214},{MI6, 1712},{LA5, 214},{DOd6, 214},{MI6, 214},{MI6, 1712},{SI5, 214},{SOLd5, 214},{LA5, 214},{SI5, 856}, {0,0}
};









