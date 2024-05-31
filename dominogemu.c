#define kDown 60
# define kRight 30

#define IsKeyDown(keyMap, theKey) (((unsigned char *)(keyMap))[(theKey) / 8] & 1 << ((theKey) % 8))

#define				keyArrowLeft			0x7b
#define				keyArrowRight			0x7c
#define				keyArrowUp				0x7e
#define				keyArrowDown			0x7d

#define				keyCommand				0x37
#define				keyOption				0x3A
#define				keyShift				0x38
#define				keyControl				0x3B
#define				keySpace				0x31
#define				keyEscape				0x35
#define				keyTab					0x 30
#define				keyBackSpace			0x33
#define				keyDelete				0x75
 #define				keyCapsLock				0x39
 
#define				keyF1					0x7A
#define				keyF2					0x78
#define				keyF3					0x63
#define				keyF4					0x76
#define				keyF5					0x60
#define				keyF6					0x61
#define				keyF7					0x62
#define				keyF8					0x64
#define				keyF9					0x65
#define				keyF10					0x6D
#define				keyF11					0x67
#define				keyF12					0x6F
#define				keyF13					0x69
#define				keyF14					0x6B
#define				keyF15					0x71

#define				keyReturn				0x24
#define				keyEnter				0x4C
#define				keyEnterPB				0x34

#define				keyPad0					0x52
#define				keyPad1					0x53
#define				keyPad2					0x54
#define				keyPad3					0x55
#define				keyPad4					0x56
#define				keyPad5					0x57
#define				keyPad6					0x58
#define				keyPad7					0x59
#define				keyPad8					0x5B
#define				keyPad9					0x5C

#define				kButtonStateOn			0
#define				kButtonStateOff			128

#include <MacWindows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <PictUtils.h>
#include <Devices.h>
#include <LowMem.h>
#include <TextUtils.h>

RGBColor gBlackColour = { 0x0000, 0x0000, 0x0000 };
RGBColor gWhiteColour = { 0xFFFF, 0xFFFF, 0xFFFF };




int i, zeit, Zeit, snd3;	
float HeldX, HeldY, HeldSz;						/*i, Zeit, X, Y-Koordinaten des Helden, Zeit zur �berpr�fung der Geschwindigkeit*/
short HState, HC, Held; 										/* Momentanzustand des Helden, Health, Z�hleinheit*/
int health, time, timev[2];	
float HP;								/* Lebenabzug, Zeit der Unverwundbarkeit (2x)*/

short P2;
float HX[2], HY[2];						/*i, Zeit, X, Y-Koordinaten des Helden, Zeit zur �berpr�fung der Geschwindigkeit*/
short HSt[2];
short WH;
short PSW;

short st;

KeyMap myKeyMap;
short l, r, u, d, f;

short SB, PB, PB2;									/*Smart Bomb, Power Bomb.*/
short sb, pb, pb2;
short bu4;

short L, P;
short random, rd, rd2, rd3, rd4;
int waitr;

short bgS, bgC, bgP;

int snd4;
int snd5, snd6;

short h62;

short zero=0, cs;											/*?, count shot*/

short CN, LV, START;

short meine, meine2;

short LT, FPS;												/*Leveltype, FPS (ticks)*/

float GX[128], GY[128], GT[128];
short GA[128], GP[128];			/*Gegnerkoordinaten X, Y, Art des Gegners, Aktivierungskoordinaten des Gegners*/
float GSzX[128], GSzY[128], GSz[128];							/*Gegner Gr�sse in X, Y Richtung, Gr�sse des Bildes des Gegners*/
float GSX[128], GSY[128];
short GC[128], GC2[128], GC3[128], GC4[128], GC5[128];									/*Hilfsz�hler 1-4 f�r  Gegner*/
short G[128], GH[128];							/*Gegner in welcher Phase: 0:Unbesetzt, oder zerst�rt, 1: Besetzt, aber noch nicht in aktion, 2: Gegner kommt ins Bild (optional), 3: Normalzustand 4:Gegner verschwindet*/
short GS, GS2, GS3, GS4, GS5;	
float GS6;										/*Gegner Share*/
short h0;
short C, C4, C16, C64, C256, C0;

short TS[8], TC[8], TX[8], TY[8], TP[8];	/*Frames vor dem Start, Dauer des Bildes, X, Y Koordinaten, Bild*/
float SX[150], SY[150], SXS[150], SYS[150]; /*Schusskoordinaten X, Y, Schussgeschwindigkeit X, Y*/
short SS[150], SP[150], SA[150], SF[150];	/* Schussgr�sse, Bild, Anzahl Bilder f�r die Animation des Schusses, Derzeitiges Bild in der Animationsphase */
short S[150]; 							/*Schuss JA/NEIN*/
short bH;						/*Hilfsvariable f�r Hintergrund, die f�r jedes P erneuert wird*/
float bS, bC, bC0, bC1, bC2, bC3, bC4, bC5, bC6, bC7;		/*Hilfen f�r Bild*/
short bl, bt, br, bb;			/*Hilfsvariablen f�r Zoomeffekte bei Hintergr�nden*/
short F[16], FX[16], FY[16];				/*Eigene Sch�sse Ja/Nein, X, Y-Koordinaten*/
short exT, exX, exY, exS, exSX, exSY;     /*Explosionsart, X, Y-Koordinate, Geschwind. des Animationsablaufes, Bewgung in X, Y Richtung d. Expl., anzahl Bilder der Animation, Gr�sse */
short exAcount[80];								/*moveenemy(0-127), moveshot(0-31), testshot(0-31), drawbackground(noch unbekannt), drawshot(0-35), Frameratevariable)*/
								/*Zufallszahl*/
float bu, bu2, bu3;						/*Hilfsvariablen, die jedes Bild erneuert werden*/
char myKey;

short bC8;

short ko, p;						/*Wie weit im Level, Welches HintergrundBild*/
float bild;							/*Y-Koordinate des Bildes (in Level 2 X-Koordinate)*/
float ko2, bild2, ko3, bild3, ko4, bild4, ko5, bild5, bild6, bild7;
float bild8, bild9, bild0;
short l,r,t,b; 	
short l2,r2,u2,d2,f2;						
short E[80], e, e2, Help[80];				/*Explosion aktiv?, hilfsvariable f�r die jew Expl., hilfsvariable f�r Geschwindigkeit*/
short exTp[80],  exXp[80],  exYp[80],  exSp[80],  exSXp[80],  exSYp[80],  pcp[80]; /*-->*/
float exsizep[80]; 							/*F�r die jeweiligen Explosionen 1-80: Type, X, Y Koordinaten, Geschwindigkeit der Animation, X, Y Geschwindigkeit, Anzahl Bilder der Animation, Gr�sse der Animation(Standard:1) */
short me, ms, ts, s, db, ds, f, ds, z, txt;		
float h1, h2;
short h3, h4, h5, h6, h7, h8;	
short h11[80];
short L2;
short PD[8], PID[8];

short snd, snd2;
		
Boolean gSoundAchtung = false;

OSErr AS_Initialise (Boolean *attnFlag,short numChannels);
OSErr AS_PlayID (short resID, short refNum);

OSErr damianIgnoriertFehler;


void AS_CloseChannel(void);
void AS_CloseDown(void);

void dobewegen ();
void createshot (float sX, float sY, float sXS, float sYS, short sS, short sP, short sA);
void test (int t);
void createenemy (int GXm, int GYm, int GTm, int GAm, short GCm, short GC2m, short GC3m, short GC4m);
void moveenemy (int me);
void shot (int s);
void drawbackground (int db);	
void drawenemy ();
void createexplosion (short exT, short exX, short exY, short exS, short exSX, short exSY, short pc, float exsize);
void drawshot (int ds);
void draw ();
void drawhero ();
void heldhit (int WH, int time, int health);
void searchshot (int searchX, int searchY, int searchS, int searchSz, int searchP, int ac);
void degreeshot (int dX, int dY, float dD, float dS, int dSz, int dP);
void text (short TSp, short TCp, short TXp, short TYp, short TPp);
void drawtext ();
void ee (int GXmm, int GYmm, int GTmm, int GAmm);
void bg ();
void specshot (int specX, int specY, float specD, float specS, float specSX, float specSY,  int specSz, int specP);
void degree (short N, short OX, short OY);
void size (float bSz, short pict);
void stopsound ();
void wait (short wait);
void SR ();
void LR ();
void dobewegenP2 ();
void list ();
void gameover ();
void reset ();
void play (short pD, short pID);
void playsound ();

/* FILESMOD-prototyp */
void DaLoadFile	(short str);



static void GetMBarRgn(RgnHandle mBarRgn);
static void SH_ForceUpdate(RgnHandle rgn);

int h, n, count;
	
	
Rect bounds;
PicHandle Sprite[200];
PicHandle Pic[45];	
PicHandle PicVG[14];
PicHandle Ex[150];
PicHandle Sh[100];
Rect Shbounds[100];
Rect OShbounds[100];	
Rect boundsS[200];
Rect boundsB[45];
Rect OboundsS[200];
Rect OboundsB[45];
Rect oldbounds;
Rect Exbounds[150];
Rect OExbounds[150];
Rect boundsVG[14];
Rect OboundsVG[14];

	
int main(void)
{
	short t, control;
	
	
	
	RgnHandle		GrayRgn = LMGetGrayRgn();
	RgnHandle			mBarRgn;
	unsigned short		mBarHeight;
	
	
	/*Standard*/
	
	QDErr help;
	WindowPtr dasWindow;
	OSStatus err = 0;
	GWorldPtr myGworld = (GWorldPtr)NewPtr(sizeof(GWorldPtr));
	GWorldPtr oldWorld = (GWorldPtr)NewPtr(sizeof(GWorldPtr));
	
	/*Sound*/
	
	
	damianIgnoriertFehler = AS_Initialise (&gSoundAchtung, 256);
	
	bild = 0;
	p=0;
	L=-1;
	FPS=3;
	SB=1;
	
	ee(0,0,36,0);
	ee(0,0,37,0);
	
	
		/*FilesMOD*/
	DaLoadFile (99);
	DaLoadFile (100);
	DaLoadFile (129);
	DaLoadFile (202);
	DaLoadFile (203);
	
	
	
	GetKeys(myKeyMap);
if (IsKeyDown(myKeyMap, keyArrowLeft))
{L=1;}	
if (IsKeyDown(myKeyMap, keyArrowRight))
{L=3;}	
if (IsKeyDown(myKeyMap, keyArrowUp))
{L=5;}
 	
/*if (u>0) {u=1;}
d = IsKeyDown(myKeyMap, keyArrowDown);	
if (d>0) {d=1;}
f = IsKeyDown(myKeyMap, keyPad0);	*/
	
	for (i=0; i<80; i++) {E[i]=-1;}
	
	
	/*Bilder Laden*/
	
	
	/*Sprites*/
	
	for (h3=0; h3<200; h3++)
	{
	Sprite[h3] = GetPicture(1000+h3);
	boundsS[h3] = ((**Sprite[h3]).picFrame);
	OboundsS[h3] = ((**Sprite[h3]).picFrame);
	}
	
	/*Explosionen*/
	
	for (n=0; n<150; n++)
	{
	Ex[n] = GetPicture(21+n);
	Exbounds[n] = ((**Ex[n]).picFrame);
	OExbounds[n] = ((**Ex[n]).picFrame);
	}

	/* Shots*/
	
	for (n=0; n<100; n++)
	{
	Sh[n] = GetPicture(200+n);
	Shbounds[n] = ((**Sh[n]).picFrame);
	OShbounds[n] = ((**Sh[n]).picFrame);
	}
	
	Pic[1] = GetPicture(11);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(12);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(303);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(304);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(305);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(306);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);	
	
	Pic[10] = GetPicture(1501);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[11] = GetPicture(1502);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1503);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1504);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1505);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	Pic[15] = GetPicture(14);
	boundsB[15] = ((**Pic[15]).picFrame);
	OboundsB[15] = ((**Pic[15]).picFrame);
	
	Pic[20] = GetPicture(131);
	boundsB[20] = ((**Pic[20]).picFrame);
	OboundsB[20] = ((**Pic[20]).picFrame);
	
	Pic[21] = GetPicture(132);
	boundsB[21] = ((**Pic[21]).picFrame);
	OboundsB[21] = ((**Pic[21]).picFrame);
	
	PicVG[0] = GetPicture(1601);
	boundsVG[0] = ((**PicVG[0]).picFrame);
	OboundsVG[0] = ((**PicVG[0]).picFrame);
	
	PicVG[1] = GetPicture(1602);
	boundsVG[1] = ((**PicVG[1]).picFrame);
	OboundsVG[1] = ((**PicVG[1]).picFrame);
	
	PicVG[2] = GetPicture(300);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	PicVG[3] = GetPicture(13);
	boundsVG[3] = ((**PicVG[3]).picFrame);
	OboundsVG[3] = ((**PicVG[3]).picFrame);
	
	PicVG[4] = GetPicture(15);
	boundsVG[4] = ((**PicVG[4]).picFrame);
	OboundsVG[4] = ((**PicVG[4]).picFrame);
	
	PicVG[5] = GetPicture(16);
	boundsVG[5] = ((**PicVG[5]).picFrame);
	OboundsVG[5] = ((**PicVG[5]).picFrame);
	
	PicVG[6] = GetPicture(17);
	boundsVG[6] = ((**PicVG[6]).picFrame);
	OboundsVG[6] = ((**PicVG[6]).picFrame);
	
	PicVG[8] = GetPicture(1521);
	boundsVG[8] = ((**PicVG[8]).picFrame);
	OboundsVG[8] = ((**PicVG[8]).picFrame);
	
	PicVG[9] = GetPicture(1522);
	boundsVG[9] = ((**PicVG[9]).picFrame);
	OboundsVG[9] = ((**PicVG[9]).picFrame);
	
	PicVG[10] = GetPicture(1523);
	boundsVG[10] = ((**PicVG[10]).picFrame);
	OboundsVG[10] = ((**PicVG[10]).picFrame);
	
	PicVG[11] = GetPicture(1524);
	boundsVG[11] = ((**PicVG[11]).picFrame);
	OboundsVG[11] = ((**PicVG[11]).picFrame);
	
	PicVG[12] = GetPicture(1525);
	boundsVG[12] = ((**PicVG[12]).picFrame);
	OboundsVG[12] = ((**PicVG[12]).picFrame);
	

	HeldSz=1;
	
	
	
	
	/*Gegner Kreieren*/ /*Level1*/
	
		
	/*Menubar ausblenden*/
	mBarHeight = GetMBarHeight();
	mBarRgn = NewRgn();
	GetMBarRgn(mBarRgn);
	LMSetMBarHeight(0);
	UnionRgn(GrayRgn,mBarRgn,GrayRgn);
	SH_ForceUpdate(mBarRgn);
	
	
	
	/*Zeichnungsebene festlegen*/
	InitGraf(&qd.thePort);
	InitWindows();
	dasWindow = GetNewCWindow(128, nil, (WindowPtr)-1);
	SetPort(dasWindow);
	err = TransitionWindow(dasWindow, kWindowZoomTransitionEffect, kWindowShowTransitionAction, nil);
	help = NewGWorld(&myGworld,0,&(dasWindow->portRect),NULL,NULL,0);
	bounds = ((**Pic[1]).picFrame); /*ACHTUNG, wenn Bild 1 nicht 640*480 ist, dann Scheisse!*/
	oldbounds=bounds;
	
	
	GetGWorld(&oldWorld,nil);
	SetGWorld(myGworld,nil);
	
	DaLoadFile (100);
	
	
	HideCursor ();

	
	/****************************** hab folgende linie auskommentiert...
	
	/*createshot (-50, -50, 0, 0, 0, 0, 0);
	##Dorian: "Diese �#�҂ Linie l�sst alles abst�rzen...warum ist die drin, die macht ja nix (sinnvolles) ?!?" 
	
	******************************* ende �nderung */
	
	/*##Damian: "Hat einen Zweck, da der Schuss an der position 0 nie richtig funktionierte.*/

	

	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	
	/*L=7;*/
	
	p=1;
	HeldX=320;
	HeldY=530;
	HP=3;
	LV=0;
	
	
	
	
	
	
	/*--------------------------------------------------------------*/
	
	
	
	/* MAIN PROGRAM LOOP*/
	
	while (!Button())
	{
	
	
	/*if (gSoundAchtung == true)
	{
	
	}*/
	
	/*Level*/
	
	
	
	if (((int)TickCount()-Zeit)>=FPS) 		/*Geschwindigkeits Regler*/
	{
	i++;
	
	Zeit=(int)TickCount();
	
	
	if (C+C4+C16==0)
	{
	AS_CloseChannel();
	}
	
	snd=0;
	
	if (IsKeyDown(myKeyMap, keyF1))
	{
	START=1;
	}
	
	/*damianIgnoriertFehler = AS_Initialise (&gSoundAchtung, 256);
	AS_CloseDown();*/
	
	
	/*Z�hlen*/
	
	if(C++>=3)
	{
	C=0;
	if(C4++>=3)
	{
	C4=0;
	if(C16++>=3)
	{
	C16=0;
	if(C64++>=3)
	{
	C64=0;
	if(C256++>=3)
	{
	C256=0;
	}
	}
	}
	}
	}
	
	if (++C0==2)
	{
	C0=0;
	}
	
	/*Zufallszahl (Jede Runde Neu)*/
	
	qd.randSeed=TickCount();
	rd=(Random()&0X7FFF)%100;
	
	qd.randSeed=TickCount()/2;
	rd2=(Random()&0X7FFF)%100;
	
	qd.randSeed=TickCount()/3;
	rd3=(Random()&0X7FFF)%100;
	
	qd.randSeed=TickCount()/4;
	rd4=(Random()&0X7FFF)%100;
	
	
	/* Hintergrund Zeichnen */
	
	LockPixels(GetGWorldPixMap(myGworld));
	
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	
	
	dobewegen ();
	if (P2)
	{
	dobewegenP2 ();
	}
	
	
	/* Intro */
	
	if (L==-1)
	{
	if (ko==0)
	{
	Pic[1] = GetPicture(11);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(12);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(303);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(304);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(305);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(306);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);	
	
	Pic[10] = GetPicture(1501);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[11] = GetPicture(1502);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1503);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1504);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1505);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	Pic[15] = GetPicture(14);
	boundsB[15] = ((**Pic[15]).picFrame);
	OboundsB[15] = ((**Pic[15]).picFrame);
	
	PicVG[0] = GetPicture(1601);
	boundsVG[0] = ((**PicVG[0]).picFrame);
	OboundsVG[0] = ((**PicVG[0]).picFrame);
	
	PicVG[1] = GetPicture(1602);
	boundsVG[1] = ((**PicVG[1]).picFrame);
	OboundsVG[1] = ((**PicVG[1]).picFrame);
	
	PicVG[2] = GetPicture(300);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	PicVG[3] = GetPicture(13);
	boundsVG[3] = ((**PicVG[3]).picFrame);
	OboundsVG[3] = ((**PicVG[3]).picFrame);
	
	PicVG[4] = GetPicture(15);
	boundsVG[4] = ((**PicVG[4]).picFrame);
	OboundsVG[4] = ((**PicVG[4]).picFrame);
	
	PicVG[5] = GetPicture(16);
	boundsVG[5] = ((**PicVG[5]).picFrame);
	OboundsVG[5] = ((**PicVG[5]).picFrame);
	
	PicVG[6] = GetPicture(17);
	boundsVG[6] = ((**PicVG[6]).picFrame);
	OboundsVG[6] = ((**PicVG[6]).picFrame);
	
	bild2=0;
	bild3=0;
	bild4=0;
	bild5=0;
	bild6=0;
	bild7=0;
	
	bC=0;
	bC1=0;
	bC2=0;
	bC3=0;
	bC4=0;
	bC5=0;
	bC6=0;
	bC7=0;
	
	text (0, 140, 320, 240, 5);
	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	HX[0]=320;
	HY[0]=530;
	
	FPS=3;
	
	DaLoadFile (143);
	damianIgnoriertFehler = AS_PlayID (12321, nil);
	
	}
	
	if (ko==157)
	{
	


	text (0, 125, 320, 240, 6);
	}
	
	if (ko==318)
	{
	text (0, 210, 320, 240, 4);
	}
	
	if (ko>160)
	{
	if (ko<640)
	{
	if (C16+C4+C==0)
	{
	text (0, 16, 320, 440, 3);
	text (32, 16, 320, 440, 3);
	}
	}
	}
	
	ko++;
	
	if (ko>100)
	{
	if (f)
	{
	ko=0;
	L++;
	P=-2;
	p=1;
	bild=0;
	HY[0]=430;
	HX[0]=330;
	HY[1]=430;
	HX[1]=270;
	HeldSz=0.4;
	stopsound();
	}
	}
	
	if (P==0)
	{
	OffsetRect(&boundsB[1], 0, -480+bild);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], 0, 0+bild);
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	bild+=2;
	if (bild>=480)
	{
	bild=0;
	p++;
	}
	if (ko>=640)
	{
	P++;
	}
	}
	
	if (P==1)
	{
	if (ko==100)
	{
	SR ();
	}
	
	if (ko==1200)
	{
	SR ();
	}
	
	OffsetRect(&boundsB[1], 0, -480+bild);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], 0, 0+bild);
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	bild+=20;
	HY[0]-=1;
	if (bild>=480)
	{
	bild=0;
	p++;
	}
	if (p>=11)
	{
	P++;
	}
	}
	
	if (P==2)
	{

	
	OffsetRect(&boundsB[2], 0, -480+bild);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	OffsetRect(&boundsB[1], 0, 0+bild);
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	bild+=5;
	HY[0]-=16;
	if (bild>=480)
	{
	bild=0;
	p++;
	}
	if (p>=12)
	{
	P++;
	}
	}
	
	if (P==3)
	{
	OffsetRect(&boundsB[15], 0, 0);		
	DrawPicture(Pic[15], &boundsB[15]);
	boundsB[15] = OboundsB[15];
	}
	}
	
	/*Level 1*/
	if (L==0)
	{
	
	/*LADEN*/
	if (P==-2)
	{
	
	reset ();
	p=1;
	
	Pic[1] = GetPicture(301);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(302);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	HY[0]=430;
	HX[0]=330;
	HY[1]=430;
	HX[1]=270;
	
	DaLoadFile (101);
	
	damianIgnoriertFehler = AS_PlayID (10, nil);
	wait (30);
	
	if (LV>=1)
	{
	createenemy (-50, 200, 0, 730, 0, 0, 4, 2);
	}
	
	SB=1;
	
	
	
	/*damianIgnoriertFehler = AS_PlayID (10, nil);*/
	
	ee (500, -50, 1, 300);
	
	ee (500, -50, 3, 320);
	ee (100, -50, 3, 340);
	
	ee (500, -50, 2, 400);
	ee (100, -50, 2, 440);
	
	ee (500, -50, 1, 500);
	ee (100, -50, 1, 500);
	ee (100, 0, 2, 600);
	ee (200, 0, 2, 650);
	ee (400, 0, 2, 610);
	ee (600, 0, 2, 630);
	ee (50, 0, 2, 660);
	ee (150, 0, 2, 620);
	ee (350, 0, 2, 660);
	ee (580, 0, 2, 680);
	ee (320, 0, 2, 700);
	ee (20, 0, 2, 710);
	ee (200, 0, 3, 800);
	ee (500, 0, 3, 800);
	ee (250, 0, 3, 915);
	ee (480, 0, 3, 960);
	ee (450, 0, 3, 950);
	ee (320, 0, 3, 970);
	ee (120, 0, 3, 980);
	ee (20, 0, 3, 1000);
	createenemy (-50, 200, 0, 1630, 0, 0, 4, 2);
	ee (320, -50, 4, 1600);
	ee (320, -50, 4, 1700);
	ee (100, -50, 4, 1700);
	ee (100, -50, 4, 1650);
	createenemy (-50, 100, 0, 1400, 0, 0, 4, 2);
	ee (200, -50, 4, 1500);
	ee (200, -50, 4, 1450);
	ee (400, -50, 4, 1600);
	ee (500, -50, 4, 1200);
	ee (500, -50, 4, 2100);
	ee (500, -50, 4, 2000);
	ee (100, -50, 4, 2000);
	createenemy (200, -50, 1, 1000,0,0,0,5);
	createenemy (100, -50, 1, 1150,0,0,3,3);
	ee (200, -50, 3, 1100);
	ee (200, -50, 3, 1150);
	ee (500, -50, 3, 1300);
	ee (200, -50, 3, 1400);
	ee (500, -50, 1, 1500);
	ee (200, -50, 3, 1480);
	ee (500, -50, 3, 1490);
	ee (500, -50, 3, 1600);
	ee (200, -50, 3, 1700);
	ee (100, 0, 2, 1800);
	ee (200, 0, 2, 1810);
	ee (300, 0, 2, 1820);
	ee (400, 0, 2, 1830);
	ee (500, 0, 2, 1840);
	ee (600, 0, 2, 1840);
	ee (50, 0, 2, 1850);
	ee (150, 0, 2, 1860);
	ee (250, 0, 2, 1870);
	ee (350, 0, 2, 1880);
	ee (480, 0, 2, 1890);
	
	if (LV)
	{
	ee (450, 0, 2, 1900);
	}
	
	ee (350, 0, 4, 1900-20*LV);
	ee (320, 0, 4, 1915-20*LV);
	ee (120, 0, 4, 1930-20*LV);
	ee (250, 0, 6, 2100);
	ee (350, 0, 1, 2200);
	ee (480, 0, 6, 2300);
	ee (580, 0, 1, 2150);
	ee (450, 0, 1, 2250);
	ee (350, 0, 6, 2350);
	ee (320, 0, 1, 2800);
	ee (50, 0, 1, 2800);
	ee (590, 0, 1, 2800);
	ee (200, 0, 1, 2820);
	ee (440, 0, 1, 2820);
	ee (50, 0, 1, 2840);
	ee (550, 0, 1, 2860);
	ee (300, 0, 1, 2860);
	ee (140, 0, 1, 2860);
	
	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	text (0, 80, 320, 240, 2);
	FPS=2;
	L=0;
	i=0;
	P++;
	
	
	}
	
	ko+=1;
	bild+=1;
	if (bild >=	480)
	{
	p++;
	bild=0;
	
	}
	
	
	
	
	/*START*/
	
	

	
	
	if (P==-1)
	{
	DrawPicture(Pic[1], &boundsB[1]);
	
	if (ko==100)
	{
	wait (400);
	}
	
	if (ko>120)
	{
	HY[0]-=0.8;
	HY[1]-=0.8;
	}
	if (ko>=180)
	{
	P++;
	}
	}
	
	if (P==0)
	{
	DrawPicture(Pic[1], &boundsB[1]);
	/*HeldSz+=0.005;*/
	HY[0]-=(HeldSz*2)+1;
	HY[1]-=(HeldSz*2)+1;
	if (ko>=210)
	{
	P++;
	
	bild=0;
	}
	}
	
	if (P==1)/*1*/
	{
	
	if (HeldSz<1)
	{
	HeldSz+=0.0075;
	HY[0]-=(HeldSz*2);
	HY[1]-=(HeldSz*2);
	}
	
	if (ko>290)
	{
	Held=1;
	}
	
	OffsetRect(&boundsB[p+1], 0, -480+bild);		
	DrawPicture(Pic[p+1], &boundsB[p+1]);
	boundsB[p+1] = OboundsB[p+1];
	
	OffsetRect(&boundsB[p], 0, 0+bild);
	DrawPicture(Pic[p], &boundsB[p]);
	boundsB[p] = OboundsB[p];
	
	
	/*if (C+C4+C16==0)
	{
	createenemy(220, 330, 52, -3, -8, -5, 0, 12);
	createenemy(220, 450, 52, -3, -8, -5, 0, 12);
	createenemy(220, 290, 52, -3, -8, -5, 0, 12);
	createenemy(220, 170, 52, -3, -8, -5, 0, 12);
	createenemy(220, 210, 52, -3, -8, -5, 0, 12);
	createenemy(220, 250, 52, -3, -8, -5, 0, 12);
	createenemy(220, 370, 52, -3, -8, -5, 0, 12);
	createenemy(220, 410, 52, -3, -8, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 8, -5, 0, 12);
	createenemy(250, 450, 52, -3, 8, -5, 0, 12);
	createenemy(250, 290, 52, -3, 8, -5, 0, 12);
	createenemy(250, 170, 52, -3, 8, -5, 0, 12);
	createenemy(250, 210, 52, -3, 8, -5, 0, 12);
	createenemy(250, 250, 52, -3, 8, -5, 0, 12);
	createenemy(250, 370, 52, -3, 8, -5, 0, 12);
	createenemy(250, 410, 52, -3, 8, -5, 0, 12);
	
	createenemy(220, 330, 52, -3, -5, -5, 0, 12);
	createenemy(220, 450, 52, -3, -5, -5, 0, 12);
	createenemy(220, 290, 52, -3, -5, -5, 0, 12);
	createenemy(220, 170, 52, -3, -5, -5, 0, 12);
	createenemy(220, 210, 52, -3, -5, -5, 0, 12);
	createenemy(220, 250, 52, -3, -5, -5, 0, 12);
	createenemy(220, 370, 52, -3, -5, -5, 0, 12);
	createenemy(220, 410, 52, -3, -5, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 5, -5, 0, 12);
	createenemy(250, 450, 52, -3, 5, -5, 0, 12);
	createenemy(250, 290, 52, -3, 5, -5, 0, 12);
	createenemy(250, 170, 52, -3, 5, -5, 0, 12);
	createenemy(250, 210, 52, -3, 5, -5, 0, 12);
	createenemy(250, 250, 52, -3, 5, -5, 0, 12);
	createenemy(250, 370, 52, -3, 5, -5, 0, 12);
	createenemy(250, 410, 52, -3, 5, -5, 0, 12);
	
	createenemy(220, 330, 52, -3, -2, -5, 0, 12);
	createenemy(220, 450, 52, -3, -2, -5, 0, 12);
	createenemy(220, 290, 52, -3, -2, -5, 0, 12);
	createenemy(220, 170, 52, -3, -2, -5, 0, 12);
	createenemy(220, 210, 52, -3, -2, -5, 0, 12);
	createenemy(220, 250, 52, -3, -2, -5, 0, 12);
	createenemy(220, 370, 52, -3, -2, -5, 0, 12);
	createenemy(220, 410, 52, -3, -2, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 2, -5, 0, 12);
	createenemy(250, 450, 52, -3, 2, -5, 0, 12);
	createenemy(250, 290, 52, -3, 2, -5, 0, 12);
	createenemy(250, 170, 52, -3, 2, -5, 0, 12);
	createenemy(250, 210, 52, -3, 2, -5, 0, 12);
	createenemy(250, 250, 52, -3, 2, -5, 0, 12);
	createenemy(250, 370, 52, -3, 2, -5, 0, 12);
	createenemy(250, 410, 52, -3, 2, -5, 0, 12);
	}*/
	 
	if (ko==1000)
 	{ 
	LR();
	}
	
	if (ko==2500)
	{
	LR();
	}
	
	if (ko==2540)
	{
	SR();
	damianIgnoriertFehler = AS_PlayID (11, nil);
	}
	
	
	if (p>=6)
	{
	P++;
	
	Pic[1] = GetPicture(307);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(312);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(313);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(308);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(1004);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(316);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	i=2400;
	}
	}
	
	if (P==2)/*2*/
	{
	bl+=4;
	bt+=3;
	SetRect (&boundsB[1], bl-640, bt-480, 1280-bl, 960-bt);
	DrawPicture(Pic[1], &boundsB[1]);
	if (i>=2560)
	{
	P++;
	bild=0;
	}
	}
	
	if (P==3)/*3*/
	{
	bild-=0.5;
	OffsetRect(&boundsB[4], 0, bild-240);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	if (i>=2900)
	{
	bild2+=9;
	OffsetRect(&boundsB[2], 0, -480+bild2+bild2);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	OffsetRect(&boundsB[3], 0, -960+bild2+bild2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	}
	if(i>=2940)
	{
	P++;
	bild=0;
	text (0, 12, 320, 240, 0);
	text (24, 12, 320, 240, 0);
	text (48, 12, 320, 240, 0);
	text (72, 12, 320, 240, 0);
	text (96, 12, 320, 240, 0);
	text (130, 120, 320, 240, 1);
	play (0,18938);
	play (24,18938);
	play (48,18938);
	play (30,9511);
	play (72,18938);
	SB++;
	}
	}
	
	if (P==4)/*4*/
	{
	bild+=19;
	OffsetRect(&boundsB[3], 0, -480+bild);		
	DrawPicture(Pic[3], &boundsB[3]);
	OffsetRect(&boundsB[3], 0, 480);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	if (i>=3250)
	{
	P++;
	ee (320, 480, 10, 0);
	DaLoadFile (103);
	damianIgnoriertFehler = AS_PlayID (20609, nil);
	snd3=(int)TickCount();
	snd2=0;
	}
	}
	
	if (P==5)/*5*/
	{
	
	if ((int)TickCount()>=snd3+3386)
	{
	snd3=(int)TickCount();
	damianIgnoriertFehler = AS_PlayID (20609, nil);
	}
	
	bild+=19;
	OffsetRect(&boundsB[3], 0, -480+bild);		
	DrawPicture(Pic[3], &boundsB[3]);
	OffsetRect(&boundsB[3], 0, 480);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	}
	
	if (P==6)/*6*/
	{
	bild+=19;
	OffsetRect(&boundsB[3], 0, -480+bild);		
	DrawPicture(Pic[3], &boundsB[3]);
	OffsetRect(&boundsB[3], 0, 480);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	if (bH>=150)
	{
	HY[0]-=8;
	HY[0]-=8;
	Held=0;
	}
	
	if (bH++==250)
	{
	stopsound ();
	L=1;
	P=0;
	bH=0;
	}
	}
	}
	
	/*Ende Level 1*/
	
	
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	
	/*Level 2*/
	
	/*Laden*/
	if (L==1)
	
	{

	reset ();
	
	Pic[1] = GetPicture(601);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(611);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(612);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(613);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(614);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(615);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(651);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);
	
	Pic[8] = GetPicture(621);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);
	
	Pic[9] = GetPicture(631);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[10] = GetPicture(622);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[11] = GetPicture(1511);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1509);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1512);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1513);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	PicVG[2] = GetPicture(600);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	PicVG[7] = GetPicture(1608);
	boundsVG[7] = ((**PicVG[7]).picFrame);
	OboundsVG[7] = ((**PicVG[7]).picFrame);
	
	
	HX[0]=-100;
	HY[0]=200;
	
	HX[1]=-100;
	HY[1]=300;
	
	LT=1;
	
	FPS=3;
	L=2;
	P=1;
	ko=0;
	p=0;
	bild2=0;
	
	text (0, 220, 320, 240, 2);
	SB++;
	
	createenemy (700, 200, 23, 2500, -6, 0, 0, -2); 
	
	createenemy (700, 100, 9, 600, -12, 1, 0, 0);
	createenemy (700, 200, 9, 600, -12, 0, 0, 0); 
	createenemy (700, 300, 9, 600, -12, 0, 0, 0); 
	createenemy (700, 400, 9, 670, -12, -1, 0, 0); 
	createenemy (700, 100, 9, 490, -12, 0, 0, 0); 
	createenemy (700, 200, 9, 480, -12, 0, 0, 0); 
	createenemy (700, 300, 9, 520, -12, 0, 0, 0); 
	createenemy (700, 400, 9, 520, -12, 0, 0, 0); 
	createenemy (700, 100, 9, 690, -12, 0, 0, 0); 
	createenemy (700, 50, 9, 520, -12, 3, 0, 0); 
	createenemy (700, 150, 9, 490, -12, 0, 0, 0); 
	createenemy (700, 250, 9, 480, -12, -1, 0, 0); 
	createenemy (700, 350, 9, 480, -12, 0, 0, 0); 
	createenemy (700, 450, 9, 470, -12, -2, 0, 0); 
	createenemy (700, 50, 9, 490, -12, 0, 0, 0); 
	createenemy (700, 150, 9, 450, -12, 1, 0, 0); 
	createenemy (700, 250, 9, 490, -12, 1, 0, 0); 
	createenemy (700, 350, 9, 500, -12, 0, 0, 0); 
	createenemy (700, 450, 9, 500, -12, -4, 0, 0); 
	createenemy (700, 50, 9, 520, -12, 6, 0, 0); 
	createenemy (700, 250, 9, 530, -12, 1, 0, 0); 
	createenemy (700, 450, 9, 550, -12, -6, 0, 0); 
	
	createenemy (700, 400, 7, 800, -6, -1, 0, -5); 
	createenemy (700, 100, 7, 890, -5, 0, 8, 8); 
	createenemy (700, 200, 7, 800, -5, 0, 0, 0); 
	createenemy (700, 300, 7, 890, -4, 0, 0, -5); 
	createenemy (700, 400, 7, 910, -8, 0, 0, 0); 
	createenemy (700, 100, 7, 910, -5, 0, 0, 0); 
	createenemy (700, 50, 7, 905, -4, 3, 2, 10); 
	createenemy (700, 150, 7, 901, -5, 0, 0, 8); 
	createenemy (700, 250, 7, 1110, -5, -1, 0, 0); 
	createenemy (700, 350, 7, 1150, -7, 0, 0, 0); 
	createenemy (700, 450, 7, 960, -7, -2, 8, -10); 
	createenemy (700, 50, 7, 1180, -5, 0, 10, 9); 
	createenemy (700, 150, 7, 990, -4, 1, 12, 8); 
	createenemy (700, 250, 7, 990, -4, 1, 8, -10); 
	createenemy (700, 350, 7, 1000, -8, 0, 8, -10); 
	createenemy (700, 450, 7, 1000, -9, -4, 0, 0); 
	createenemy (700, 50, 7, 1000, -8, 6, 0, 0); 
	createenemy (700, 250, 7, 1020, -2, 1, 0, 10); 
	createenemy (700, 450, 7, 1020, -1, -6, 0, -10); 
	
	createenemy (700, 50, 9, 800, -12, 5, 0, 0); 
	createenemy (700, 150, 9, 800, -12, 3, 0, 0); 
	createenemy (700, 250, 9, 800, -12, -3, 0, 0); 
	createenemy (700, 350, 9, 800, -12, -5, 0, 0); 
	createenemy (700, 450, 9, 850, -12, -4, 0, 0); 
	createenemy (700, 50, 9, 850, -12, 6, 0, 0); 
	createenemy (700, 250, 9, 900, -12, 1, 0, 0); 
	createenemy (700, 450, 9, 1000, -12, -6, 0, 0);
	
	createenemy (700, 300, 8, 1150, -2, -1, 0, 0);
	
	createenemy (700, 100, 9, 1280, -12, 1, 0, 0);
	createenemy (700, 200, 9, 1250, -12, 0, 0, 0); 
	createenemy (700, 300, 9, 1260, -12, 0, 0, 0); 
	createenemy (700, 400, 9, 1270, -12, -1, 0, 0); 
	createenemy (700, 100, 9, 1290, -12, 0, 0, 0); 
	createenemy (700, 200, 9, 1300, -12, 0, 0, 0); 
	createenemy (700, 300, 7, 1310, -4, 0, 0, 0); 
	createenemy (700, 400, 9, 1320, -12, 0, 0, 0); 
	createenemy (700, 100, 9, 1330, -12, 0, 0, 0); 
	createenemy (700, 50, 9, 1340, -12, 3, 0, 0); 
	createenemy (700, 150, 9, 1350, -12, 0, 0, 0); 
	createenemy (700, 250, 9, 1360, -12, -1, 0, 0); 
	createenemy (700, 350, 9, 1370, -12, 0, 0, 0); 
	createenemy (700, 450, 9, 1380, -12, -2, 0, 0); 
	createenemy (700, 50, 9, 1390, -12, 0, 0, 0); 
	createenemy (700, 150, 7, 1400, -4, 6, 0, 0); 
	createenemy (700, 250, 7, 1400, -4, 0, 0, 0); 
	createenemy (700, 350, 7, 1400, -4, -6, 0, 0); 
	createenemy (700, 450, 7, 1450, -4, -4, 0, 2); 
	createenemy (700, 50, 7, 1450, -4, 6, 0, -5); 
	createenemy (700, 250, 9, 1500, -6, 1, 0, 0); 
	createenemy (700, 450, 9, 1550, -6, -6, 0, 0); 
	
	createenemy (700, 50, 9, 1600, -12, 0, 0, 0); 
	createenemy (700, 150, 7, 1600, -4, 6, 0, 0); 
	createenemy (700, 250, 7, 1650, -4, 0, 0, 0); 
	createenemy (700, 350, 7, 1650, -4, -6, 0, 0); 
	createenemy (700, 450, 7, 1650, -4, -4, 0, 2); 
	createenemy (700, 50, 7, 1700, -4, 6, 0, -5); 
	createenemy (700, 250, 9, 1700, -6, 1, 0, 0); 
	createenemy (700, 450, 9, 1700, -6, -6, 0, 0); 
	
	createenemy (700, 50, 9, 1800, -12, 0, 0, 0); 
	
	if (LV)
	{
	createenemy (700, 150, 9, 1800, -10, 6, 0, 0); 
	createenemy (700, 250, 9, 1800, -12, 0, 0, 0); 
	createenemy (700, 350, 9, 1800, -10, -6, 0, 0); 
	createenemy (700, 450, 7, 1800, -4, -4, 0, 0); 
	}
	
	createenemy (700, 50, 7, 1750, -4, 6, 0, 0); 
	createenemy (700, 250, 9, 1760, -3, 1, 0, -5); 
	createenemy (700, 450, 9, 1770, -3, -6, 0, 5); 
	
	createenemy (-100, 200, 21, 1830, 12, 0, 0, 0); 
	
	if (LV)
	{
	createenemy (-100, 300, 21, 1830, 12, 0, 0, 0); 
	createenemy (-100, 100, 21, 1850, 12, 0, 0, 0); 
	createenemy (-100, 300, 21, 1850, 12, 0, 0, 0); 
	createenemy (-100, 400, 21, 1850, 12, 0, 0, 0); 
	}
	createenemy (-100, 420, 21, 1880, 12, 0, 0, 0); 
	createenemy (-100, 100, 21, 1880, 12, 0, 0, 0); 
	
	if (LV)
	{
	createenemy (-100, 400, 21, 1930, 12, -5, 0, 0); 
	createenemy (-100, 350, 21, 1930, 12, -5, 0, 0); 
	createenemy (-100, 100, 21, 1950, 12, 2, 0, 0); 
	}
	
	createenemy (-100, 300, 21, 1950, 12, 2, 0, 0); 
	
	if (LV)
	{
	createenemy (-100, 400, 21, 1950, 12, 0, 0, 0); 
	createenemy (-100, 420, 21, 1980, 12, -2, 0, 0); 
	createenemy (-100, 50, 21, 2000, 12, 0, 0, 0); 
	}
	
	if (LV)
	{
	createenemy (700, 250, 9, 2200, -6, 1, 0, 0); 
	createenemy (700, 450, 9, 2050, -6, -1, 0, 0); 
	}
	
	createenemy (700, 50, 8, 1940, -2, 1, 0, 0);
	
	createenemy (-100, 250, 21, 2200, 12, -4, 0, 0); 
	
	if (LV)
	{
	createenemy (-100, 50, 21, 2240, 12, 3, 0, 0); 
	createenemy (-100, 200, 21, 2300, 12, 3, 0, 0); 
	}
	
	createenemy (-100, 450, 21, 2300, 12, -5, 0, 0); 
	createenemy (-100, 420, 21, 2350, 12, -2, 0, 0); 
	createenemy (-100, 50, 21, 2270, 12, 2, 0, 0); 
	
	
	createenemy (700, 50, 9, 2410, -12, 3, 0, 0); 
	
	
	createenemy (700, 150, 9, 2410, -12, 0, 0, 0); 
	createenemy (700, 250, 9, 2410, -12, -1, 0, 0); 
	createenemy (700, 350, 9, 2420, -12, 0, 0, 0); 
	
	createenemy (700, 450, 9, 2420, -12, -2, 0, 0); 
	createenemy (700, 50, 9, 2480, -12, 0, 0, 0);
	
	
	createenemy (700, 400, 7, 2680, -8, -1, 0, -5); 
	createenemy (700, 100, 7, 2680, -7, 0, 8, 8);  
	
	createenemy (700, 150, 21, 2730, -12, 6, 0, 0); 
	createenemy (700, 250, 21, 2740, -12, -6, 0, 0); 
	createenemy (700, 350, 21, 2750, -12, -1, 0, 0); 
	
	createenemy (700, 150, 21, 2760, -12, 3, 0, 0); 
	createenemy (700, 250, 21, 2770, -12, -3, 0, 0); 
	createenemy (700, 350, 21, 2780, -12, -5, 0, 0); 
	
	createenemy (700, 150, 21, 2790, -12, 4, 0, 0); 
	createenemy (700, 250, 21, 2840, -12, -3, 0, 0); 
	createenemy (700, 350, 21, 2820, -12, -1, 0, 0); 
	
	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	
	
	DaLoadFile (111);
	damianIgnoriertFehler = AS_PlayID (15445, nil);
	
	snd4=(int)TickCount();
	snd5=0;
	snd6=0;
	Held=0;
	
	}
	
	
	
	/*START*/
	
	if (L==2)
	{
	ko++;
	
	
	snd3=(int)TickCount()-snd4;
	snd5++;
	if (snd3>=ko*3)
	{
	if (P<=14)
	{
	ko++;
	}
	
	if (P==2)
	{
	bild+=32;
	}
	
	if (P==3)
	{
	bild2+=0.6;
	}
	
	if (P==4)
	{
	bild2+=0.6;
	}
	
	if (P==5)
	{
	bild+=32;
	}
	
	if (P==6)
	{
	bild+=32;
	}
	
	if (P==8)
	{
	bild+=32;
	bild2+=3;
	}
	
	if (P==9)
	{
	
	bH++;
	
	bild+=32;
	if (bild >=	755)
	{
	bild-=755;
	}
	
	bild2+=22;
	if (bild2 >= 496)
	{
	bild2-=496;
	}
	
	bild3+=16;
	if (bild3 >= 378)
	{
	bild3-=378;
	}
	
	bild4+=9;
	if (bild4 >= 283)
	{
	bild4-=283;
	}
	
	bild5+=4;
	if (bild5 >= 142)
	{
	bild5-=142;
	}
	
	if (bild6<100)
	{
	if (bH<100)
	{
	bild6+=2;
	}
	}
	}
	
	if (P==10)
	{
	bild+=32;
	bild2-=4;
	}
	
	if (P==11)
	{
	bild2+=0.61;
	}
	
	if (P==12)
	{
	bild2+=0.61;
	}
	
	if (P==13)
	{
	bild+=40;
	}
	
	if (P==14)
	{
	bild+=40;
	}
	
	}
	
	
	
	if (ko==2000)
	{
	LR();
	}
	
	if (ko==3000)
	{
	LR();
	}
	
	if (P==1)
	{
	
	if (ko==52)
	{
	
	}
	
	OffsetRect(&boundsB[1], 0, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	if (ko>355)
	{
	if (ko<=365)
	{
	HX[0]+=20;
	}
	}
	if (ko>365)
	{
	P++;
	Held=1;
	}
	}
	
	
	if (P==2)
	{
	Held=1;
	bild+=32;
	if (bild>=640)
	{
	bild=0;
	p++;
	}
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], -bild+640, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	if (p>=33)
	{
	P++;
	bild=0;
	}
	
	}
	
	if (P==3)
	{
	bild+=32;
	if (bild>=1100)
	{
	bild=0;
	P++;
	}
	bild2+=0.4;
	OffsetRect(&boundsB[9], -bild2, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[8], 640-bild, 0);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	
	if (P==4)
	{
	bild2+=0.6;
	OffsetRect(&boundsB[9], -bild2, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	if (bild2>=160)
	{
	P++;
	bild2=0;
	}
	}
	
	if (P==5)
	{
	bild+=32;
	if(bild>=1280)
	{
	bild=0;
	P++;
	p=0;
	}
	OffsetRect(&boundsB[9], -160, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[10], -bild+647, 0);		
	DrawPicture(Pic[10], &boundsB[10]);
	boundsB[10] = OboundsB[10];
	
	OffsetRect(&boundsB[1], -bild+1280, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	}
	
	if (P==6)
	{
	bild+=32;
	if(bild>=640)
	{
	bild=0;
	p++;
	}
	
	OffsetRect(&boundsB[1], -bild+640, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	if(p>=12)
	{
	bH=640;
	P++;
	}
	}
	
	if (P==7)
	{
	SR();
	P++;
	bild2=0;
	Pic[1] = GetPicture(602);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	bild2=0;
	}
	
	
	if (P==8)
	{
	bild+=32;
	bild2+=3;
	if(bild>=755)
	{
	bild=0;
	}
	
	DrawPicture(Pic[7], &boundsB[7]);
	
	OffsetRect(&boundsB[2], -bild, -363+bild2);		
	DrawPicture(Pic[2], &boundsB[2]);
	OffsetRect(&boundsB[2], 755, 0);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2]=OboundsB[2];
	
	OffsetRect(&boundsB[1], -bild, bild2);		
	DrawPicture(Pic[1], &boundsB[1]);
	OffsetRect(&boundsB[1], 755, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1]=OboundsB[1];
	
	
	if (bild2>=420)
	{
	bH=0;
	P++;
	bild2=0;
	FPS=3;
	}
	}
	
	if (P==9)
	{
	
	bild+=32;
	if (bild >=	755)
	{
	bild-=755;
	}
	
	bild2+=22;
	if (bild2 >= 496)
	{
	bild2-=496;
	}
	
	bild3+=16;
	if (bild3 >= 378)
	{
	bild3-=378;
	}
	
	bild4+=9;
	if (bild4 >= 283)
	{
	bild4-=283;
	}
	
	bild5+=4;
	if (bild5 >= 142)
	{
	bild5-=142;
	}
	
	if (bild6<100)
	{
	if (bH<100)
	{
	bild6+=2;
	}
	}
	
	/*Hintergrund*/
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	/*Hinterste Ebene (142/70)*/
	OffsetRect(&boundsB[6], -bild5+142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5, 75+(5*bild6/100));
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5+6*142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5+2*142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5+3*142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5+4*142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], -bild5+5*142, 75+(5*bild6/100));		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	
	
	
	/*Zweithinterste Ebene(283/136)*/
	OffsetRect(&boundsB[5], -bild4+3*283, 70+(50*bild6/100));		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	OffsetRect(&boundsB[5], -bild4, 70+(50*bild6/100));
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	OffsetRect(&boundsB[5], -bild4+283, 70+(50*bild6/100));		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	OffsetRect(&boundsB[5], -bild4+(2*283), 70+(50*bild6/100));		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	
	/*Dritthinterste Ebene (378/183)*/
	OffsetRect(&boundsB[4], -bild3+2*378, 65+(105*bild6/100));		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	OffsetRect(&boundsB[4], -bild3, 65+(105*bild6/100));
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	OffsetRect(&boundsB[4], -bild3+378, 65+(105*bild6/100));		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	
	
	/*Zweitvordesrste Ebene (496/241)*/
	OffsetRect(&boundsB[3], -bild2+496, 60+(160*bild6/100));		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	OffsetRect(&boundsB[3], -bild2, 60+(160*bild6/100));
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	OffsetRect(&boundsB[3], -bild2+2*496, 60+(160*bild6/100));		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	
	/*Vorderste Ebene (755/364)*/
	OffsetRect(&boundsB[2], -bild+755, 50+(250*bild6/100));		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	OffsetRect(&boundsB[2], -bild, 50+(250*bild6/100));
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	if (bH++>346)
	{
	bild6-=2.5;
	if (bild6<=0)
	{
	P++;
	FPS=3;
	bild2=420;
	bild3=0;
	bild4=0;
	bild5=0;
	bild6=0;
	}
	}
	}
	
	if (P==10)
	{
	bild+=32;
	bild2-=4;
	if(bild>=755)
	{
	bild=0;
	}
	
	DrawPicture(Pic[7], &boundsB[7]);
	
	OffsetRect(&boundsB[2], -bild, -363+bild2);		
	DrawPicture(Pic[2], &boundsB[2]);
	OffsetRect(&boundsB[2], 755, 0);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2]=OboundsB[2];
	
	OffsetRect(&boundsB[1], -bild, bild2);		
	DrawPicture(Pic[1], &boundsB[1]);
	OffsetRect(&boundsB[1], 755, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1]=OboundsB[1];
	if (bild2<=0)
	{
	P++;
	p=0;
	bild=0;
	Pic[9] = GetPicture(632);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[1] = GetPicture(601);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	}
	}
	
	if (P==11)
	{
	bild+=32;
	
	if (p<8)
	{
	if (bild>=640)
	{
	bild=0;
	p++;
	}
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], -bild+640, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	}
	
	if (p>=8)
	{
	if (bild>=1280)
	{
	bild=0;
	P++;
	}
	bild2+=0.5;
	OffsetRect(&boundsB[9], -bild2, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[8], 640-bild, 0);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	}
	
	if (P==12)
	{
	bild2+=0.61;
	OffsetRect(&boundsB[9], -bild2, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	if (bild2>=160)
	{
	P++;
	bild2=0;
	}
	}
	
	if (P==13)
	{
	bild+=40;
	if(bild>=1280)
	{
	bild=0;
	P++;
	p=0;
	
	}
	
	OffsetRect(&boundsB[9], -160, 0);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[10], -bild+647, 0);		
	DrawPicture(Pic[10], &boundsB[10]);
	boundsB[10] = OboundsB[10];
	
	OffsetRect(&boundsB[1], -bild+1280, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	p++;
	
	text (260, 6, 320, 240, 0);
	text (272, 6, 320, 240, 0);
	text (224, 6, 320, 240, 0);
	text (236, 6, 320, 240, 0);
	text (248, 6, 320, 240, 0);
	play (260,18938);
	play (272,18938);
	play (224,18938);
	play (236,18938);
	play (248,18938);
	}
	
	if (P==14)
	{
	bild+=41;
	if(bild>=640)
	{
	bild=0;
	p++;
	}
	
	OffsetRect(&boundsB[1], -bild+640, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	if(p>=19)
	{
	bH=640;
	P++;
	bild=0;
	
	Pic[9] = GetPicture(633);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	
	
	
	
	}
	}
	
	
	if (P==15)
	{
	bild+=32;
	if (bild>=1280)
	{
	createenemy (340, 140, 11, 0, 185, 0, 0, 0);
	createenemy (340, 105, 11, 0, 167, 0, 0, 0);
	createenemy (340, 70, 11, 0, 149, 0, 0, 0);
	bild=0;
	ko=-40;
	P++;
	SR();
	
	Pic[1] = GetPicture(634);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(635);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(636);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	}
	OffsetRect(&boundsB[9], 0, 0);
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[1], -bild, 0);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[8], -bild+640, 0);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	
	if (P==16)
	{
	DrawPicture(Pic[9], &boundsB[9]);
	if (ko==30)
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==40) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==45) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==61) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==64) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==85) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==88) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==90) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==120) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==125) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==129) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==132) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==134) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==136) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (138, nil);
	}
	if (ko==138) 
	{
	DrawPicture(Pic[1], &boundsB[1]);
	damianIgnoriertFehler = AS_PlayID (504, nil);
	}
	if (ko>139) 
	{
	if (ko<200)
	{
	DrawPicture(Pic[1], &boundsB[1]);
	}
	}
	if (ko==220)
	{
	DaLoadFile (113);
	damianIgnoriertFehler = AS_PlayID (18772, nil);
	
	
	SB++;
	text (60, 6, 320, 240, 0);
	text (72, 6, 320, 240, 0);
	text (24, 6, 320, 240, 0);
	text (36, 6, 320, 240, 0);
	text (48, 6, 320, 240, 0);
	text (55, 60, 260, 270, 7);
	}
	if (ko>280)
	{
	P++;
	createenemy (560, -50, 12, 370, 0, 0, 0, 0);
	createenemy (580, -50, 13, 312, 330, 0, 0, 0);
	createenemy (580, -50, 13, 341, 230, 1, 0, 0);
	
	}
	}
	
	if (P==17)
	{
	DrawPicture(Pic[3], &boundsB[3]);
	}
	
	if (P==18)
	{
	DrawPicture(Pic[3], &boundsB[3]);
	if (ko>100)
	{
	L++;
	stopsound ();
	}
	}
	
	}
	
	/*Ende Level 2*/
	
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	/*------------------------------------------------------------*/
	
	/*Level 3 LADEN*/
	
	if (L==3)
	{
	
	reset ();
	
	FPS=3;
	SB++;
	Pic[1] = GetPicture(501);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(511);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(512);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(513);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(514);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[0] = GetPicture(515);
	boundsB[0] = ((**Pic[0]).picFrame);
	OboundsB[0] = ((**Pic[0]).picFrame);
	
	Pic[6] = GetPicture(522);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);	
	
	Pic[7] = GetPicture(523);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[8] = GetPicture(524);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);	
	
	Pic[9] = GetPicture(525);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);	
	
	Pic[11] = GetPicture(1502);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1503);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1504);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1505);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	Pic[15] = GetPicture(1603);
	boundsB[15] = ((**Pic[15]).picFrame);
	OboundsB[15] = ((**Pic[15]).picFrame);
	
	PicVG[2] = GetPicture(500);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	text (20, 460, 320, 240, 2);
	
	HX[0]=260;
	HY[0]=240;
	
	HX[1]=380;
	HY[1]=240;
	
	Held=0;
	
	/*createenemy (-60, 120, 33, 500, 0, 0, 0, 0);
	createenemy (700, 130, 33, 530, 0, 0, 0, 0);
	createenemy (700, 140, 33, 560, 0, 0, 0, 0);
	createenemy (-80, 120, 33, 590, 0, 0, 0, 0);
	createenemy (-80, 180, 33, 600, 0, 0, 0, 0);
	
	createenemy (-60, 120, 33, 600, 0, 0, 0, 0);
	createenemy (700, 130, 33, 630, 0, 0, 0, 0);
	createenemy (700, 140, 33, 660, 0, 0, 0, 0);
	createenemy (-80, 120, 33, 690, 0, 0, 0, 0);
	createenemy (720, 180, 33, 600, 0, 0, 0, 0);*/
	
	
	ee(400, -50, 1,500);
	ee(200, -50, 1,520);
	if (LV)
	{
	ee(100, -50, 1,540);
	}
	ee(300, -50, 1,560);
	
	
	
	ee(400, -50, 1,650);
	ee(200, -50, 1,600);
	ee(100, -50, 1,550);
	ee(300, -50, 4,560);
	ee(400, -50, 4,700);
	ee(200, -50, 4,720);
	
	ee(150, -50, 4,620);
	if (LV)
	{
	ee(350, -50, 4,640);
	}
	ee(400, -50, 4,660);
	ee(50, -50, 4,770);
	ee(150, -50, 4,800);
	ee(350, -50, 4,850);
	
	createenemy (700, 140, 33, 900, 0, 0, 0, 0);
	createenemy (-80, 120, 33, 950, 0, 0, 0, 0);
	
	ee(320, 600, 25,2084);
	ee(320, 600, 26,2084);
	
	ee(400, -50, 2,1200);
	ee(400, -50, 2,1205);
	ee(400, -50, 2,1210);
	ee(400, -50, 2,1215);
	ee(400, -50, 2,1220);
	ee(400, -50, 2,1225);
	ee(400, -50, 2,1230);
	ee(100, -50, 2,1200);
	ee(100, -50, 2,1205);
	ee(100, -50, 2,1210);
	ee(100, -50, 2,1215);
	ee(100, -50, 2,1220);
	ee(100, -50, 2,1225);
	ee(100, -50, 2,1230);
	
	
	ee(320, 220, 24,1200);
	ee(340, 220, 24,1050);
	ee(400, 230, 24,1080);
	if (LV)
	{
	ee(250, 210, 24,1290);
	ee(400, 250, 24,1120);
	}
	
	if (LV)
	{
	ee(350, 250, 24,1180);
	}
	createenemy (700, 140, 33, 1300, 0, 0, 0, 0);
	
	
	ee(100, -50, 2,1500);
	ee(600, -50, 2,1450);
	ee(100, -50, 2,1480);
	ee(600, -50, 2,1490);
	ee(100, -50, 2,1420);
	ee(300, -50, 2,1480);
	ee(600, -50, 2,1440);
	
	createenemy (700, 140, 33, 1500, 0, 0, 0, 0);
	createenemy (-80, 120, 33, 1590, 0, 0, 0, 0);
	
	ee(200, -50, 2,1500);
	ee(620, -50, 2,1550);
	ee(150, -50, 2,1580);
	ee(50, -50, 2,1590);
	ee(200, -50, 2,1520);
	ee(400, -50, 2,1580);
	ee(500, -50, 2,1540);
	
	ee(200, -50, 4,1600);
	ee(620, -50, 4,1650);
	ee(50, -50, 4,1690);
	if (LV)
	{
	ee(200, -50, 4,1620);
	ee(400, -50, 4,1680);
	}
	ee(500, -50, 4,1640);
	
	ee(50, -50, 2,1605);
	ee(50, -50, 2,1660);
	ee(50, -50, 2,1630);
	ee(50, -50, 2,1650);
	if (LV)
	{
	ee(600, -50, 2,1690);
	}
	ee(600, -50, 2,1680);
	ee(600, -50, 2,1640);
	
	
	ee(300, -50, 2,1900);
	ee(100, -50, 2,1805);
	ee(50, -50, 2,1910);
	ee(600, -50, 2,1815);
	ee(500, -50, 2,1820);
	ee(50, -50, 2,1925);
	ee(50, -50, 2,1830);
	ee(600, -50, 2,1900);
	ee(400, -50, 2,1905);
	ee(600, -50, 2,1910);
	ee(50, -50, 2,1815);
	ee(150, -50, 2,1820);
	ee(600, -50, 2,1825);
	ee(250, -50, 2,1830);
	
	ee(200, 220, 24,2100);
	ee(400, 210, 24,2130);
	ee(250, -50, 2,2140);
	
	ee(320, 220, 24,2230);
	ee(340, -50, 2,2290);
	ee(400, -50, 2,2240);
	ee(250, -50, 2,2250);
	ee(400, -50, 2,2260);
	ee(350, -50, 2,2270);
	
	ee(360, 200, 24,2330);
	ee(50, -50, 2,2390);
	ee(300, -50, 2,2340);
	ee(50, -50, 2,2350);
	ee(600, -50, 2,2360);
	if (LV)
	{
	ee(400, -50, 2,2370);
	}
	ee(560, 210, 2,2380);
	
	ee(280, 200, 24,2430);
	ee(600, -50, 2,2490);
	ee(500, -50, 2,2440);
	ee(600, -50, 2,2450);
	ee(500, -50, 2,2460);
	ee(600, -50, 2,2470);
	
	if (LV)
	{
	ee(50, -50, 2,2480);
	ee(280, 200, 24,2530);
	ee(200, -50, 2,2590);
	ee(100, -50, 2,2540);
	}
	
	ee(50, -50, 2,2550);
	ee(0, -50, 2,2560);
	ee(550, -50, 2,2570);
	ee(600, 210, 2,2580);
	
	ee(600, -50, 2,2690);
	ee(500, -50, 2,2640);
	ee(400, -50, 2,2650);
	ee(300, -50, 2,2660);
	ee(200, -50, 2,2670);
	ee(100, 210, 2,2680);
	ee(50, -50, 2,2690);
	if (LV)
	{
	ee(50, -50, 2,2640);
	ee(200, -50, 2,2650);
	}
	ee(300, -50, 2,2660);
	ee(400, -50, 2,2670);
	ee(500, 210, 2,2680);
	
	if (LV)
	{
	ee(600, -50, 2,2710);
	ee(520, -50, 2,2720);
	ee(440, -50, 2,2730);
	ee(360, -50, 2,2740);
	ee(280, -50, 2,2750);
	ee(200, -50, 2,2760);
	}
	ee(120, -50, 2,2770);
	ee(40, -50, 2,2780);
	
	if (LV)
	{
	ee(600, -50, 2,2710);
	ee(520, -50, 2,2720);
	ee(440, -50, 2,2730);
	ee(360, -50, 2,2740);
	ee(280, -50, 2,2750);
	ee(200, -50, 2,2760);
	}
	
	ee(180, -50, 2,2770);
	ee(40, 210, 2,2780);
	
	
	/*ee(300, -50, 2,1100);
	ee(400, -50, 2,1111);
	ee(500, -50, 2,1120);
	ee(600, -50, 2,1130);
	ee(500, -50, 2,1140);
	ee(600, -50, 2,1150);
	ee(400, -50, 2,1160);
	ee(600, -50, 6,1170);
	ee(300, -50, 2,1180);
	ee(200, -50, 2,1200);
	ee(300, -50, 2,1210);
	ee(600, -50, 2,1230);
	ee(400, -50, 2,1240);
	ee(300, -50, 2,1250);
	
	ee(300, -50, 2,1300);
	ee(400, -50, 2,1311);
	ee(500, -50, 2,1320);
	ee(600, -50, 2,1330);
	ee(500, -50, 2,1340);
	ee(600, -50, 2,1350);
	ee(400, -50, 2,1260);
	ee(600, -50, 6,1270);
	ee(300, -50, 4,1280);
	ee(200, -50, 4,1300);
	ee(300, -50, 6,1310);
	ee(600, -50, 2,1330);
	ee(400, -50, 2,1340);
	ee(300, -50, 2,1350);*/
	
	
	
	
	/*ee(150, -100, 16, 1200);   /*BOSS SCHWAGI*/
	/*ee(490, -100, 16, 1200);*/
	
	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	L++;
	bild=0;
	bild2=0;
	bild3=0;
	bild4=0;
	bild5=0;
	bild6=0;
	bH=1;
	
	p=0;
	P=0;
	ko=0;
	LT=0;
	FPS=3;
	bS=1;
	bC=1;
	bC1=1;
	bC2=1;
	bC3=1;
	bC4=1;
	bC5=1;
	
	DaLoadFile (121);
	damianIgnoriertFehler = AS_PlayID (27993, nil);
	snd4=(int)TickCount();
	snd5=0;
	snd6=0;
	
	
	}
	
	/* Level 3 START*/
	
	if (L==4)
	{
	
	
	snd3=(int)TickCount()-snd4;
	snd5++;
	snd6+=FPS;
	if (snd3*snd5/snd6>=ko)
	{
	ko++;
	
	
	if (P==2)
	{
	
	bC1=bC1/1.015;
	if (ko>=1444)
	{
	P++;
	}
	}
	
	if (P==3)
	{
	bC1=bC1*1.025;
	bC6+=0.1*bC6;
	}
	
	if (P==5)
	{
	bC1=bC1*0.97852;
	bC6-=0.1*bC6;
	}
	
	
	}
	
	ko++;
	bild+=bC*bC1*20;
	bild2+=bC*bC1*13;
	bild2+=bC7;
	bild3+=bC*bC1*8;
	bild4+=bC*bC1*5;
	bild7+=bC*bC1*3;
	
	bild6+=bC*2;
	if (bild>=bC5)
	{
	bild-=bC5;
	}
	if (bild<0)
	{
	bild+=bC5;
	}
	
	if (bild2>=bC2)
	{
	bild2-=bC2;
	}
	if (bild2<0)
	{
	bild2+=bC2;
	}
	
	if (bild3>=bC3)
	{
	bild3-=bC3;
	}
	if (bild3<0)
	{
	bild3+=bC3;
	}
	
	if (bild4>=bC4)
	{
	bild4-=bC4;
	}
	if (bild4<0)
	{
	bild4+=bC4;
	}
	
	if (bild5>=480)
	{
	bild5-=480;
	}
	if (bild5<0)
	{
	bild5+=480;
	}
	
	if (bild6>=480)
	{
	bild6-=480;
	}
	if (bild6<0)
	{
	bild6+=480;
	}
	
	if (bild7>=bC0)
	{
	bild7-=bC0;
	}
	
	if (bild7<0)
	{
	bild7+=bC0;
	}
	
	if (P==0)
	{
	
	if (ko>=500)
	{
	if (ko<=520)
	{
	Held=1;
	}
	}
	
	size (bC1, 5);
	bC4=(boundsB[5].bottom)-(boundsB[5].top);
	
	size (bC1, 4);
	bC3=(boundsB[4].bottom)-(boundsB[5].top);
	
	size (bC1, 3);
	bC2=(boundsB[3].bottom)-(boundsB[4].top);
	
	size (bC1, 2);
	bC5=(boundsB[2].bottom)-(boundsB[4].top);
	
	size (bC1, 0);
	bC0=(boundsB[0].bottom)-(boundsB[0].top);
	
	bild5+=bS;
	
	OffsetRect(&boundsB[1], 0, -480+bild5);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], 0, 0+bild5);
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	if (ko>818)
	{
	bS+=0.5;
	}
	
	if (ko>=870)
	{
	P=1;
	bild5=0;
	}
	}







	if (P>=1)
	{
	/*bC1=1.22-(0.02875*C+0.115*C4);*/
	bild5+=20;
	
	if (bC1>2.2)
	{
	DrawPicture(Pic[15], &OboundsB[15]);
	}
	
	if (ko==1000)
	{
	LR();
	}
	
	
	if (ko==2000)
	{
	LR();
	}
	
	if (ko==2600)
	{
	LR();
	}
	
	
	
	/*3. Reihe*/
	for (bu=0; bu<4; bu+=2)
	{
	if (C16==bu)
	{
	if (C4==1)
	{
	OffsetRect(&boundsB[6], 220, bild6);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	OffsetRect(&boundsB[6], 220, bild6-480);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	}
	
	if (C4==2)
	{
	OffsetRect(&boundsB[7], 220, bild6);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	OffsetRect(&boundsB[7], 220, bild6-480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	
	if (C4==3)
	{
	OffsetRect(&boundsB[8], 220, bild6);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	OffsetRect(&boundsB[8], 220, bild6-480);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	
	if (C4==0)
	{
	OffsetRect(&boundsB[9], 220, bild6);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	OffsetRect(&boundsB[9], 220, bild6-480);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	}
	}
	}
	
	for (bu=1; bu<=4; bu+=2)
	{
	if (C16==bu)
	{
	if (C4==0)
	{
	OffsetRect(&boundsB[6], 220, bild6);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	OffsetRect(&boundsB[6], 220, bild6-480);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	}
	
	if (C4==3)
	{
	OffsetRect(&boundsB[7], 220, bild6);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	OffsetRect(&boundsB[7], 220, bild6-480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	
	if (C4==2)
	{
	OffsetRect(&boundsB[8], 220, bild6);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	OffsetRect(&boundsB[8], 220, bild6-480);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	
	if (C4==1)
	{
	OffsetRect(&boundsB[9], 220, bild6);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	OffsetRect(&boundsB[9], 220, bild6-480);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	}
	}
	}
	
	if (ko<640)
	{
	bC1=1;
	}
	
	/*5. Reihe*/
	
	if (bC1<18)
	{
	size (bC1, 0);
	bC0=(boundsB[0].bottom)-(boundsB[0].top);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7-bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+2*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+3*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+4*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+5*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+6*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+7*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	/*2.*/
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7-bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+2*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+3*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+4*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+5*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+6*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+7*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	}
	
	if (bC1<1.5)
	{
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+8*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+9*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+8*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+9*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	}
	
	if (bC1<0.9)
	{
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+10*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+11*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+10*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+11*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	}
	
	if (bC1<0.7)
	{
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320-0.7*bC6-(bC1*40)-bC0/2, bild7+12*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	size (bC1, 0);
	OffsetRect(&boundsB[0], 320+0.7*bC6+(bC1*40), bild7+12*bC0);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	}
	
	/*4. Reihe*/
	if (bC1<7)
	{
	size (bC1, 5);
	bC4=(boundsB[5].bottom)-(boundsB[5].top);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4-bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4+bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4+2*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4+3*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*58)-bC4/2, bild4+4*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4-bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4+bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4+2*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4+3*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*58), bild4+4*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	}
	
	/*wenn klein*/
	
	if (bC1<1)
	{
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*55)-bC4/2, bild4+5*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*55), bild4+5*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320-1.2*bC6-(bC1*55)-bC4/2, bild4+6*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	size (bC1, 5);
	OffsetRect(&boundsB[5], 320+1.2*bC6+(bC1*55), bild4+6*bC4);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	}
	
	/*3. Reihe*/
	if (bC1<3.2)
	{
	size (bC1, 4);
	bC3=(boundsB[4].bottom)-(boundsB[4].top);
	
	OffsetRect(&boundsB[4], 320-1.9*bC6-(bC1*87.5)-bC3/2, bild3-bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320-1.9*bC6-(bC1*87.5)-bC3/2, bild3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320-1.9*bC6-(bC1*87.5)-bC3/2, bild3+bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320-1.9*bC6-(bC1*87.5)-bC3/2, bild3+2*bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320+1.9*bC6+(bC1*87.5), bild3-bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320+1.9*bC6+(bC1*87.5), bild3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320+1.9*bC6+(bC1*87.5), bild3+bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320+1.9*bC6+(bC1*87.5), bild3+2*bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	}
	
	if (bC1<1)
	{
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320-1.9*bC6-(bC1*87.5)-bC3/2, bild3+3*bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	size (bC1, 4);
	OffsetRect(&boundsB[4], 320+1.9*bC6+(bC1*87.5), bild3+3*bC3);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	}
	
	/*Zweite Reihe*/
	if (bC1<2.4)
	{
	size (bC1, 3);
	bC2=(boundsB[3].bottom)-(boundsB[3].top);
	
	OffsetRect(&boundsB[3], 320-3*bC6-(bC1*129.5)-bC2/2, bild2-bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320-3*bC6-(bC1*129.5)-bC2/2, bild2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320-3*bC6-(bC1*129.5)-bC2/2, bild2+bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	
	/*2*/
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320+3*bC6+(bC1*129.5), bild2-bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320+3*bC6+(bC1*129.5), bild2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320+3*bC6+(bC1*129.5), bild2+bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	}
	
	if (bC1<0.9)
	{
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320-3*bC6-(bC1*129.5)-bC2/2, bild2+2*bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	size (bC1, 3);
	OffsetRect(&boundsB[3], 320+3*bC6+(bC1*129.5), bild2+2*bC2);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	}
	
	/*Vorderste Ebene*/
	if (bC1<1.6)
	{
	size (bC1, 2);
	bC5=(boundsB[2].bottom)-(boundsB[2].top);
	
	OffsetRect(&boundsB[2], 320-4*bC6-(bC1*220)-bC5/2, bild-bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320-4*bC6-(bC1*220)-bC5/2, bild);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320-4*bC6-(bC1*220)-bC5/2, bild+bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320+4*bC6+(bC1*220), bild-bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320+4*bC6+(bC1*220), bild);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320+4*bC6+(bC1*220), bild+bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	}
	
	if (bC1<0.6)
	{
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320-4*bC6-(bC1*220)-bC5/2, bild+2*bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	size (bC1, 2);
	OffsetRect(&boundsB[2], 320+4*bC6+(bC1*220), bild+2*bC5);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	}
	
	
	/*VG*/
	if (ko<=894)
	{
	OffsetRect(&boundsB[1], 0, bild5);
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	}
	
	if (P==1)
	{
	if (ko>=1420)
	{
	P++;
	}
	}
	}
	/*--------------------------------*/
	if (P==2)
	{
	FPS=5;
	
	bC1=bC1/1.015;
	
	if (ko>=1444)
	{
	P++;
	}
	}
	
	if (P==3)
	{
	bC1=bC1*1.025;
	bC6+=0.1*bC6;
	if (ko>=1564)
	{
	P++;
	}
	}
	
	
	if (P==4)
	{
	FPS=3;
	if (ko>=1764)
	{
	P=5;
	FPS=5;
	
	}
	}
	
	if (P==5)
	{
	bC1=bC1*0.98156;
	bC6-=0.1*bC6;
	if (ko>=1904)
	{
	ko-=20;
	bC1=1;
	bC6=0;
	P++;
	FPS=3;
	SR();
	}
	}
	
	if (P==6)
	{
	if (ko>=2084)
	{
	bC1=1;
	bC6=0;
	P=99;
	FPS=3;
	}
	}
	
	if (P==99)
	{
	if (ko>=2940)
	{
	bC1=1;
	bC6=0;
	P=7;
	DaLoadFile (122);
	damianIgnoriertFehler = AS_PlayID (19699, nil);
	}
	}
	
	if (P==7)
	{
	FPS=4;
	bC-=0.005;
	bC6-=0.02;
	if (bC<=0.1)
	{
	P++;
	SB++;
	ee(320, -100, 20, 0); /*BOSS A1*/
	ee(320, -100, 17, 0);
	ko=1000;
	FPS=3;
	}
	}
	
	if (P==8)
	{
	}
	
	if (P==9)
	{
	
	}
	
	if (P==10)
	{
	bC8++;
	if (bC8>0)
	{
	createexplosion (5, rd*6.4, 470-C4*8, 2, 0, -C*4, 6, 1.5);
	createexplosion (5, rd2*6.4, 470-C4*8, 2, 0, -C*4, 6, 1.5);
	createexplosion (5, rd3*6.4, 470-C4*8, 2, 0, -C*4, 6, 1.5);
	createexplosion (5, rd4*6.4, 470-C4*8, 2, 0, -C*4, 6, 1.5);
	if (C0)
	{
	if (bC8<100)
	{
	damianIgnoriertFehler = AS_PlayID (1270, nil);
	}
	}
	bC8++;
	}
	if (bC8>=300)
	{
	P++;
	bC8=0;
	}
	}

	if (P==101)
	{
	if (bC8<=0)
	{
	damianIgnoriertFehler = AS_PlayID (504, nil);
	}
	bC8++;
	if (bC8<30)
	{
	DrawPicture(PicVG[6], &boundsVG[6]);
	}
	}
	}
	
	
	
	
	
	
	
	
	
	
	/*Level 4-----------------------------------------------*/
	
	
	
	if (L==5)
	{
	
	
	
	if (P==0)
	{
	
	reset ();
	
	DaLoadFile (129);
	
	FPS=3;
	SB++;
	
	Pic[1] = GetPicture(401);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(402);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(403);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(404);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(405);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(406);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(407);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[8] = GetPicture(408);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);	
	
	Pic[9] = GetPicture(411);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[10] = GetPicture(412);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[0] = GetPicture(413);
	boundsB[0] = ((**Pic[0]).picFrame);
	OboundsB[0] = ((**Pic[0]).picFrame);
	
	Pic[19] = GetPicture(1604);
	boundsB[19] = ((**Pic[19]).picFrame);
	OboundsB[19] = ((**Pic[19]).picFrame);
	
	
	
	
	
	/*createenemy (-150, 120, 30, 20, 5, 1, 0, 0);
	
	createenemy (-150, 240, 30, 80, 4, 0, 0, 0);
	createenemy (650, 100, 30, 60, -3, 2, 0, 0);
	createenemy (-150, 550, 30, 100, 4, -4, 0, 0);
	
	ee(50,-50,2,150);
	ee(150,-50,2,180);
	ee(50,-50,2,170);
	ee(250,-50,2,150);
	ee(50,-50,2,150);
	ee(50,-50,2,170);
	ee(550,-50,2,180);*/ 
	
	createenemy (-150, 240, 30, 60, 4, 0, 0, 0);
	createenemy (650, 100, 30, 160, -3, 2, 0, 0);
	createenemy (-150, 550, 30, 120, 4, -4, 0, 0);
	
	createenemy (-50, 100, 0, 363, 0, 0, 4, 2);
	createenemy (-50, 100, 0, 373, 0, 0, 4, 2);
	createenemy (690, 50, 0, 383, 0, 0, -4, 2);
	createenemy (690, 50, 0, 353, 0, 0, -4, 2);
	createenemy (-50, 100, 0, 363, 0, 0, 4, 2);
	createenemy (-50, 100, 0, 373, 0, 0, 4, 2);
	createenemy (690, 150, 0, 383, 0, 0, -4, 2);
	createenemy (690, -50, 0, 393, 0, 0, -4, 2);
	createenemy (-50, 250, 0, 390, 0, 0, 4, 2);
	createenemy (-50, 0, 0, 395, 0, 0, 4, 2);
	createenemy (690, 100, 0, 400, 0, 0, -4, 2);
	createenemy (300, -80, 0, 405, 0, 0, 0, 4);
	
	createenemy (-150, 240, 30, 720, 4, 0, 0, 0);
	createenemy (650, 100, 30, 740, -3, 2, 0, 0);
	createenemy (-150, 550, 30, 760, 4, -4, 0, 0);
	createenemy (-150, 240, 30, 780, 4, 0, 0, 0);
	createenemy (650, 100, 30, 600, -3, 2, 0, 0);
	createenemy (-150, 550, 30, 520, 4, -4, 0, 0);
	createenemy (-150, 240, 30, 540, 4, 0, 0, 0);
	createenemy (650, 100, 30, 560, -3, 2, 0, 0);
	createenemy (-150, 550, 30, 580, 4, -4, 0, 0);
	
	createenemy (-150, 120, 29, 600, 7, 1, 0, 0);
	
	/*ee(320,140, 50, 3850);*/
	
	ee(50,-50,2,850);
	ee(150,-50,2,880);
	ee(50,-50,2,870);
	ee(250,-50,2,850);
	ee(50,-50,2,850);
	ee(50,-50,2,870);
	ee(550,-50,2,880);
	
	ee(400, -50, 2,1000);
	ee(400, -50, 2,1005);
	ee(400, -50, 2,1010);
	ee(400, -50, 2,1015);
	ee(400, -50, 2,1020);
	ee(400, -50, 2,1025);
	ee(400, -50, 2,1030);
	ee(100, -50, 2,1000);
	ee(100, -50, 2,1005);
	ee(100, -50, 2,1010);
	ee(100, -50, 2,1015);
	ee(100, -50, 2,1020);
	ee(100, -50, 2,1025);
	ee(100, -50, 2,1030);
	
	ee(700, 100, 33,1200);
	ee(400, -50, 2,1205);
	ee(400, -50, 2,1310);
	ee(400, -50, 2,1315);
	ee(400, -50, 2,1320);
	ee(-50, 150, 33,1325);
	ee(400, -50, 2,1330);
	ee(100, -50, 2,1300);
	ee(100, -50, 2,1305);
	ee(700, 150, 33,1310);
	ee(100, -50, 2,1250);
	ee(100, -50, 2,1320);
	ee(100, -50, 2,1325);
	ee(100, 150, 2,1330);
	
	ee(600, -50, 2,1420);
	ee(233, -50, 2,1430);
	ee(500, 150, 2,1400);
	
	ee(133, -50, 2,1460);
	ee(499, -50, 2,1470);
	ee(300, 150, 2,1450);
	
	ee(110, -50, 5,2900);
	ee(110, -50, 5,2940);
	ee(110, -50, 5,2980);
	ee(110, -50, 5,3020);
	ee(110, -50, 5,3060);
	ee(110, -50, 5,3100);
	ee(110, -50, 5,3140);
	ee(110, -50, 5,3180);
	ee(110, -50, 5,3220);
	ee(110, -50, 5,3260);
	ee(110, -50, 5,3300);
	
	createenemy (-100, 50, 29, 1500, 6, 1, 0, 0);
	createenemy (750, 50, 29, 1600, -6, 1, 0, 0);
	
	createenemy (200, -50, 30, 1750, 0, 4, 0, 0);
	createenemy (600, -50, 30, 1760, 0, 4, 0, 0);
	createenemy (400, -50, 30, 1720, 0, 4, 0, 0);
	
	createenemy (100, 530, 30, 1740, 0, -4, 0, 0);
	createenemy (620, 530, 30, 1740, 0, -4, 0, 0);
	
	ee(400, -50, 2,1900);
	ee(400, -50, 2,1910);
	ee(400, -50, 2,1920);
	ee(400, -50, 2,1930);
	ee(400, -50, 2,1930);
	ee(400, -50, 2,1940);
	ee(400, -50, 2,1950);
	ee(100, -50, 2,1960);
	ee(100, -50, 2,1970);
	ee(100, -50, 2,1930);
	ee(100, -50, 2,1950);
	ee(100, -50, 2,1960);
	ee(100, -50, 2,1970);
	ee(100, -50, 2,1940);
	
	ee(340, 209, 24,1900);
	
	
	ee(170, -100, 31,2100);
	ee(490, -100, 31,2100);
	createenemy (320, -100, 29, 2100, 0, 1, 12, 12);
	
	
	createenemy (320, 120, 32, 2300, 200, 0, 12, 0);
	createenemy (320, 240, 32, 2350, 200, 0, 12, 0);
	createenemy (150, 150, 32, 2380, 200, 0, 12, 0);
	createenemy (320, 240, 32, 2420, 200, 0, 12, 0);
	createenemy (180, 240, 32, 2440, 200, 0, 12, 0);
	createenemy (500, 190, 32, 2480, 200, 0, 12, 0);
	createenemy (180, 260, 32, 2540, 200, 0, 12, 0);
	
	if (LV)
	{
	createenemy (380, 260, 32, 2620, 200, 0, 12, 0);
	}
	
	
	createenemy (320, 390, 32, 2660, 200, 0, 12, 0);
	
	
	ee (80,50,28,1900);
	ee (270,50,27,1900);
	ee (460,50,28,1900);
	ee (650,50,27,1900);
	
	ee (80,170,27,1900);
	ee (270,170,28,1900);
	ee (460,170,27,1900);
	ee (650,170,28,1900);
	
	ee (80,290,28,1900);
	ee (270,290,27,1900);
	ee (460,290,28,1900);
	ee (650,290,27,1900);
	
	ee (80,410,27,1900);
	ee (270,410,28,1900);
	ee (460,410,27,1900);
	ee (650,410,28,1900);
 	
	
	meine=-1;
	
	
	
	
	createshot (-15, -15, 0, 0, 0, 0, 0);
	
	wait (240);
	
	DaLoadFile (131);
	damianIgnoriertFehler = AS_PlayID (15445, nil);
	snd4=(int)TickCount();
	
	P=1;
	
	/*P++;*/
	bild=0;
	bild2=0;
	bild3=0;
	bild4=0;
	bild5=0;
	bild6=0;
	bild7=0;
	bH=0;
	bC=1;
	bC1=0;
	p=1;
	Held=1;
	HX[0]=260;
	HY[0]=380;
	HX[1]=380;
	HY[1]=380;
	
	snd3=0;
	snd5=0;
	snd6=0;
	}
	
	if (P==1)
	{
	snd3=(int)TickCount()-snd4;
	snd5++;
	snd6+=FPS;
	if (snd3*snd5/snd6>=ko)
	{
	ko++;
	
	
	/*ko='s*/
	
	/*if (ko==1)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=8;
	}
	*/
	
	
	if (ko==340)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	LR ();
	}
	
	if (ko==470)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	}
	
	if (ko==1040)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	}
	
	if (ko==1165)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1290)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1415)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1540)
	{
	SR();
	/*bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;*/
	}
	
	
	if (ko==2900)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=15;
	}
	
	/**/
	
	if (bC1<3)
	{
	bild+=bC*2;
	}
	
	if (bC>=0)
	{
	bild2+=30;
	bild3+=30;
	}
	
	if (bC<0)
	{
	bild2-=30;
	bild3-=30;
	}
	
	}
	
	ko++;
	
	if (bC1<3)
	{
	bild+=bC*2;
	}
	
	if (bC>=0)
	{
	bild2+=30;
	bild3+=30;
	}
	
	if (bC<0)
	{
	bild2-=30;
	bild3-=30;
	}
	
	if (ko<=3)
	{
	bild3=0;
	bild2=0;
	bC1=3;
	bC2=17;
	}
	
	
	if (bild>=480)
	{
	bild-=480;
	p++;
	}
	
	if (bild<0)
	{
	bild+=480;
	p--;
	}
	
	
	if (bild2>=480)
	{
	bild2-=480;
	bC2--;
	}
	
	if (bild2<0)
	{
	bild2+=480;
	bC2--;
	}
	
	if (bild3>=960)
	{
	bild3-=960;
	}
	
	if (bild3<=0)
	{
	bild3+=960;
	}
	}
	
	if (P==1)
	{
	
	
	if (ko>=2000)
	{
	if (meine==-1)
	{
	ee(400, -50, 2,3620);
	ee(400, -50, 2,3530);
	ee(100, -50, 2,3650);
	ee(700, 150, 33,3310);
	ee(100, -50, 2,3650);
	ee(100, -50, 2,3620);
	LR ();
	
	/*ee(320,140, 50, 3900);*/
	
	meine=0;
	}
	}
	if (p==8)
	{
	if (meine==0)
	{
	Pic[1] = GetPicture(408);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(409);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(420);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(421);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(422);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(1603);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(431);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[8] = GetPicture(433);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);
	
	PicVG[0] = GetPicture(1601);
	boundsVG[0] = ((**PicVG[0]).picFrame);
	OboundsVG[0] = ((**PicVG[0]).picFrame);
	
	PicVG[1] = GetPicture(432);
	boundsVG[1] = ((**PicVG[1]).picFrame);
	OboundsVG[1] = ((**PicVG[1]).picFrame);
	
	
	p=1;
	meine=1;
	}
	}
	
	if (bC1<=2)
	{
	OffsetRect(&boundsB[p+1], 0, bild-480);		
	DrawPicture(Pic[p+1], &boundsB[p+1]);
	boundsB[p+1] = OboundsB[p+1];
	
	OffsetRect(&boundsB[p], 0, bild);		
	DrawPicture(Pic[p], &boundsB[p]);
	boundsB[p] = OboundsB[p];
	}
	
	if (ko>=3810)
	{
	if (meine2==0)
	{
	meine2=1;
	/*DaLoadFile (133);
	damianIgnoriertFehler = AS_PlayID (14151, nil);
	snd5=(int)TickCount();*/
	}
	}
	
	if (meine==1)
	{
	if (p==7)
	{
	meine=10;
	text (24, 12, 320, 240, 0);
	text (48, 12, 320, 240, 0);
	text (72, 12, 320, 240, 0);
	text (92, 12, 320, 240, 0);
	text (110, 12, 320, 240, 0);
	text (130, 100, 320, 300, 1);
	
	play (24,18938);
	play (48,18938);
	play (72,18938);
	play (92,18938);
	play (110,18938);
	}
	}
	
	if (meine==10)
	{
	if (p==8)
	{
	P=10;
	ko=3799;
	}
	}
	
	/*if (ko==1600)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=10;
	}
	*/
	
	if (ko==1)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=8;
	}
	
	if (ko==340)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	LR ();
	}
	
	if (ko==470)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	}
	
	if (ko==1040)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	
	}
	
	if (ko==1165)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1290)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1415)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;
	}
	
	if (ko==1540)
	{
	SR();
	/*bild3=0;
	bild2=0;
	bC1=1;
	bC2=4;*/
	}
	
	
	if (ko==2080)
	{
	LR();
	}
	
	
	if (ko>=2500)
	{
	if (ko<=2505)
	{
	GS=27;
	GS2=27;
	GS3=27;

	bild3=0;
	bild2=0;
	bC1=1;
	bC2=14;
	
	Pic[18] = GetPicture(1604);
	boundsB[18] = ((**Pic[18]).picFrame);
	OboundsB[18] = ((**Pic[18]).picFrame);
	}
	}
	
	if (ko==2900)
	{
	bild3=0;
	bild2=0;
	bC1=1;
	bC2=15;
	}
	
	if (bC1==1)
	{
	OffsetRect(&boundsB[9], 0, bild3-480);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[10], 0, bild3-960);		
	DrawPicture(Pic[10], &boundsB[10]);
	boundsB[10] = OboundsB[10];
	
	if (bild3>=900)
	{
	bC1=3;
	}
	}
	
	if (bC1==3)
	{
	OffsetRect(&boundsB[10], 0, bild2);		
	DrawPicture(Pic[10], &boundsB[10]);
	OffsetRect(&boundsB[10], 0, -480);		
	DrawPicture(Pic[10], &boundsB[10]);
	boundsB[10] = OboundsB[10];
	
	if (bC2<=0)
	{
	bC1=2;
	bild3=0;
	}
	
	}
	
	if (bC1==2)
	{
	OffsetRect(&boundsB[0], 0, bild3-471);		
	DrawPicture(Pic[0], &boundsB[0]);
	boundsB[0] = OboundsB[0];
	
	OffsetRect(&boundsB[10], 0, bild3);		
	DrawPicture(Pic[10], &boundsB[10]);
	boundsB[10] = OboundsB[10];
	
	if (bild3>=920)
	{
	bC1=0;
	}
	}
	}
	
	if (P==10)
	{
	Pic[1] = GetPicture(433);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(435);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(436);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(437);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(438);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(439);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(440);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[8] = GetPicture(441);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);	
	
	Pic[9] = GetPicture(442);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[10] = GetPicture(443);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[0] = GetPicture(434);
	boundsB[0] = ((**Pic[0]).picFrame);
	OboundsB[0] = ((**Pic[0]).picFrame);
	
	Pic[23] = GetPicture(444);
	boundsB[23] = ((**Pic[23]).picFrame);
	OboundsB[23] = ((**Pic[23]).picFrame);
	
	Pic[24] = GetPicture(445);
	boundsB[24] = ((**Pic[24]).picFrame);
	OboundsB[24] = ((**Pic[24]).picFrame);
	
	Pic[25] = GetPicture(446);
	boundsB[25] = ((**Pic[25]).picFrame);
	OboundsB[25] = ((**Pic[25]).picFrame);
	
	Pic[26] = GetPicture(447);
	boundsB[26] = ((**Pic[26]).picFrame);
	OboundsB[26] = ((**Pic[26]).picFrame);
	
	Pic[27] = GetPicture(448);
	boundsB[27] = ((**Pic[27]).picFrame);
	OboundsB[27] = ((**Pic[27]).picFrame);
	
	Pic[28] = GetPicture(449);
	boundsB[28] = ((**Pic[28]).picFrame);
	OboundsB[28] = ((**Pic[28]).picFrame);
	
	Pic[29] = GetPicture(450);
	boundsB[29] = ((**Pic[29]).picFrame);
	OboundsB[29] = ((**Pic[29]).picFrame);
	
	Pic[30] = GetPicture(451);
	boundsB[30] = ((**Pic[30]).picFrame);
	OboundsB[30] = ((**Pic[30]).picFrame);
	
	Pic[31] = GetPicture(452);
	boundsB[31] = ((**Pic[31]).picFrame);
	OboundsB[31] = ((**Pic[31]).picFrame);
	
	Pic[32] = GetPicture(453);
	boundsB[32] = ((**Pic[32]).picFrame);
	OboundsB[32] = ((**Pic[32]).picFrame);
	
	Pic[33] = GetPicture(454);
	boundsB[33] = ((**Pic[33]).picFrame);
	OboundsB[33] = ((**Pic[33]).picFrame);
	
	Pic[34] = GetPicture(455);
	boundsB[34] = ((**Pic[34]).picFrame);
	OboundsB[34] = ((**Pic[34]).picFrame);
	
	Pic[35] = GetPicture(456);
	boundsB[35] = ((**Pic[35]).picFrame);
	OboundsB[35] = ((**Pic[35]).picFrame);
	
	Pic[36] = GetPicture(457);
	boundsB[36] = ((**Pic[36]).picFrame);
	OboundsB[36] = ((**Pic[36]).picFrame);
	
	Pic[37] = GetPicture(458);
	boundsB[37] = ((**Pic[37]).picFrame);
	OboundsB[37] = ((**Pic[37]).picFrame);
	
	DaLoadFile (133);
	damianIgnoriertFehler = AS_PlayID (15445, nil);
	/*DaLoadFile (131);
	damianIgnoriertFehler = AS_PlayID (15445, nil);*/
	snd4=(int)TickCount();
 	
 	ee (320, -100, 38, 0);
	
	P++;
	bild=0;
	p=1;
	bC=1;
	bC1=0;
	bC2=0;
	}

	if (P>=11)
	{
	
	bild+=bC;
	
	if (bild>=478)
	{
	bild-=478;
	}
	
	bC1+=bC2;
	
	if (bC1>=1000)
	{
	bC1=0;
	p++;
	}
	
	if (p>=11)
	{
	if (p<23)
	{
	p=23;
	}
	}
	
	
	if (p>=33)
	{
	p=1;
	}
	
	OffsetRect(&boundsB[p], 0, -478+bild);		
	DrawPicture(Pic[p], &boundsB[p]);
	boundsB[p] = OboundsB[p];
	
	OffsetRect(&boundsB[p], 0, 0+bild);
	DrawPicture(Pic[p], &boundsB[p]);
	boundsB[p] = OboundsB[p];
	
	
	
	if ((int)TickCount()-snd4>6950)
	{
	snd4=(int)TickCount();
	damianIgnoriertFehler = AS_PlayID (15445, nil);
	}
	}
	
	if (P==12)
	{
	if (bild5>130)
	{
	Held=0;
	HY[0]-=12;
	HY[1]-=12;
	}
	
	if (bild5++>180)
	{
	L=6;
	P=0;
	stopsound ();
	}
	}
	
	
	}
	
	
	
	
	
	/*L6----------------------------------------------*/
	if (L==6)
	{
	if (P==0)
	{
	Pic[1] = GetPicture(901);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(902);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(911);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(912);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(913);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(1603);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(1609);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[9] = GetPicture(921);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[19] = GetPicture(1604);
	boundsB[19] = ((**Pic[19]).picFrame);
	OboundsB[19] = ((**Pic[19]).picFrame);	
	
	/*Pic[9] = GetPicture(411);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[10] = GetPicture(412);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[0] = GetPicture(413);
	boundsB[0] = ((**Pic[0]).picFrame);
	OboundsB[0] = ((**Pic[0]).picFrame);*/
	
	Pic[23] = GetPicture(901);
	boundsB[23] = ((**Pic[23]).picFrame);
	OboundsB[23] = ((**Pic[23]).picFrame);
	
	Pic[24] = GetPicture(901);
	boundsB[24] = ((**Pic[24]).picFrame);
	OboundsB[24] = ((**Pic[24]).picFrame);
	
	Pic[25] = GetPicture(901);
	boundsB[25] = ((**Pic[25]).picFrame);
	OboundsB[25] = ((**Pic[25]).picFrame);
	
	Pic[26] = GetPicture(902);
	boundsB[26] = ((**Pic[26]).picFrame);
	OboundsB[26] = ((**Pic[26]).picFrame);
	
	Pic[27] = GetPicture(902);
	boundsB[27] = ((**Pic[27]).picFrame);
	OboundsB[27] = ((**Pic[27]).picFrame);
	
	Pic[28] = GetPicture(902);
	boundsB[28] = ((**Pic[28]).picFrame);
	OboundsB[28] = ((**Pic[28]).picFrame);
	
	Pic[29] = GetPicture(902);
	boundsB[29] = ((**Pic[29]).picFrame);
	OboundsB[29] = ((**Pic[29]).picFrame);
	
	Pic[30] = GetPicture(902);
	boundsB[30] = ((**Pic[30]).picFrame);
	OboundsB[30] = ((**Pic[30]).picFrame);
	
	Pic[31] = GetPicture(10000);
	boundsB[31] = ((**Pic[31]).picFrame);
	OboundsB[31] = ((**Pic[31]).picFrame);
	
	Pic[32] = GetPicture(10000);
	boundsB[32] = ((**Pic[32]).picFrame);
	OboundsB[32] = ((**Pic[32]).picFrame);
	
	Pic[33] = GetPicture(10000);
	boundsB[33] = ((**Pic[33]).picFrame);
	OboundsB[33] = ((**Pic[33]).picFrame);
	
	Pic[34] = GetPicture(10000);
	boundsB[34] = ((**Pic[34]).picFrame);
	OboundsB[34] = ((**Pic[34]).picFrame);
	
	Pic[35] = GetPicture(10000);
	boundsB[35] = ((**Pic[35]).picFrame);
	OboundsB[35] = ((**Pic[35]).picFrame);
	
	Pic[36] = GetPicture(10000);
	boundsB[36] = ((**Pic[36]).picFrame);
	OboundsB[36] = ((**Pic[36]).picFrame);
	
	Pic[37] = GetPicture(10000);
	boundsB[37] = ((**Pic[37]).picFrame);
	OboundsB[37] = ((**Pic[37]).picFrame);
	
	PicVG[0] = GetPicture(1601);
	boundsVG[0] = ((**PicVG[0]).picFrame);
	OboundsVG[0] = ((**PicVG[0]).picFrame);
	
	PicVG[1] = GetPicture(920);
	boundsVG[1] = ((**PicVG[1]).picFrame);
	OboundsVG[1] = ((**PicVG[1]).picFrame);
	
	PicVG[7] = GetPicture(900);
	boundsVG[7] = ((**PicVG[7]).picFrame);
	OboundsVG[7] = ((**PicVG[7]).picFrame);
	
	
	text (0, 2, 320, 240, 7);
	
	
	
	
	P++;
	ko=0;
	bC=0;
	Held=1;
	FPS=3;
	
	createenemy (360, 240, 45, 0, 0, 3, 0, 0);
	createenemy (100, 300, 45, 0, 0, -3, 0, 0);
	createenemy (200, 350, 45, 0, 0, 3, 0, 0);
	createenemy (350, 150, 45, 0, 0, -4, 0, 0);
	createenemy (150, 300, 45, 0, 0, 3, 0, 0);
	createenemy (400, 240, 45, 0, 0, -4, 0, 0);
	createenemy (320, 300, 45, 0, 2, 0, 0, 0);
	createenemy (320, 200, 45, 0, -3, 0, 0, 0);
	createenemy (400, 300, 45, 0, 4, 0, 0, 0);
	
	createenemy (320, 200, 45, 0, 0, 3, 0, 0);
	createenemy (300, 300, 45, 0, 0, -3, 0, 0);
	createenemy (280, 200, 45, 0, 0, 3, 0, 0);
	createenemy (260, 400, 45, 0, 0, -4, 0, 0);
	createenemy (240, 100, 45, 0, 0, 3, 0, 0);
	createenemy (340, 400, 45, 0, 0, -4, 0, 0);
	createenemy (360, 200, 45, 0, 2, 0, 0, 0);
	createenemy (380, 300, 45, 0, -3, 0, 0, 0);
	createenemy (400, 350, 45, 0, 4, 0, 0, 0);
	
	createenemy (420, 300, 45, 0, 0, 3, 0, 0);
	createenemy (440, 230, 45, 0, 0, -3, 0, 0);
	createenemy (150, 200, 45, 0, 0, 3, 0, 0);
	createenemy (160, 170, 45, 0, 0, -4, 0, 0);
	createenemy (200, 440, 45, 0, 0, 3, 0, 0);
	createenemy (240, 370, 45, 0, 0, -4, 0, 0);
	createenemy (280, 365, 45, 0, 2, 0, 0, 0);
	createenemy (320, 350, 45, 0, -3, 0, 0, 0);
	createenemy (260, 340, 45, 0, 4, 0, 0, 0);
	
	createenemy (500, 100, 45, 0, 0, 3, 0, 0);
	createenemy (650, 400, 45, 0, 0, -3, 0, 0);
	createenemy (620, 120, 45, 0, 0, 3, 0, 0);
	createenemy (600, 420, 45, 0, 0, -4, 0, 0);
	createenemy (580, 80, 45, 0, 0, 5, 0, 0);
	createenemy (560, 60, 45, 0, 0, -4, 0, 0);
	createenemy (540, 460, 45, 0, 2, 0, 0, 0);
	createenemy (520, 0, 45, 0, -5, 0, 0, 0);
	createenemy (500, 480, 45, 0, 5, 0, 0, 0);
	
	createenemy (0, 100, 45, 0, 0, 3, 0, 0);
	createenemy (20, 400, 45, 0, 0, -3, 0, 0);
	createenemy (40, 300, 45, 0, 0, 3, 0, 0);
	createenemy (60, 100, 45, 0, 0, -4, 0, 0);
	createenemy (80, 50, 45, 0, 0, 3, 0, 0);
	createenemy (100, 25, 45, 0, 0, -4, 0, 0);
	createenemy (120, 75, 45, 0, 2, 0, 0, 0);
	createenemy (150, 90, 45, 0, -3, 0, 0, 0);
	createenemy (30, 410, 45, 0, 4, 0, 0, 0);
	
	createenemy (420, 230, 45, 0, 0, 3, 0, 0);
	createenemy (440, 420, 45, 0, 0, -3, 0, 0);
	createenemy (150, 200, 45, 0, 0, 3, 0, 0);
	createenemy (160, 110, 45, 0, 0, -4, 0, 0);
	createenemy (200, 120, 45, 0, 0, 3, 0, 0);
	createenemy (240, 320, 45, 0, 0, -4, 0, 0);
	createenemy (280, 380, 45, 0, 2, 0, 0, 0);
	createenemy (320, 480, 45, 0, -3, 0, 0, 0);
	createenemy (260, 470, 45, 0, 4, 0, 0, 0);
	
	
	createenemy (420, -50, 2, 330, 0, 3, 0, 0);
	createenemy (300, -50, 2, 350, 0, -3, 0, 0);
	createenemy (150, -50, 2, 370, 0, 3, 0, 0);
	createenemy (200, -50, 2, 390, 0, -4, 0, 0);
	createenemy (430, -50, 2, 400, 0, 3, 0, 0);
	createenemy (600, -50, 2, 410, 0, -4, 0, 0);
	createenemy (430, -50, 2, 430, 2, 0, 0, 0);
	createenemy (50, -50, 2, 440, -3, 0, 0, 0);
	createenemy (180, -50, 2, 460, 4, 0, 0, 0);
	
	HX[0]=320;
	HY[0]=550;
	Held=0;
	
	}
	

	ko++;
	
	
	if (ko==2)
	{
	wait (400);
	}
	
	if (ko==3)
	{
	DaLoadFile	(171);
	damianIgnoriertFehler = AS_PlayID (14151, nil);
	}
	
	if (ko>=299)
	{
	if (ko<=314)
	{
	HY[0]-=10;
	if (ko==313)
	{
	Held=1;
	}
	}
	}
	
	
	if (P==1)
	{
	
	
	DrawPicture(Pic[6], &boundsB[6]);
	bC++;
	if (bC>=300)
	{
	GS=10;
	P++;
	bild=0;
	p =0;
	}
	}
	
	if (P==2)
	{
	
	bild+=32;
	
	DrawPicture(Pic[6], &boundsB[6]);
	
	OffsetRect(&boundsB[3], 0, -480+bild);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	OffsetRect(&boundsB[4], 0, -960+bild);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	if (bild>=960)
	{
	P++;
	bild=0;
	}
	}
	
	
	
	if (P==3)
	{
	bild+=32;
	
	
	
	OffsetRect(&boundsB[4], 0, bild);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	OffsetRect(&boundsB[4], 0, -480+bild);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	
	
	if (bild>=480)
	{
	bild-=480;
	p++;
	}
	
	if (p>=15)
	{
	P++;
	bild2=320;
	bild3=240;
	bild4=320;
	bild5=240;
	bC1=0.76;
	bC2=0.76;
	bC3=0.76;
	bC4=0.76;
	
	
	
	text (24, 8, 320, 240, 0);
	text (40, 8, 320, 240, 0);
	text (56, 8, 320, 240, 0);
	text (72, 8, 320, 240, 0);
	text (88, 8, 320, 240, 0);
	text (100, 100, 320, 300, 1);
	
	play (24,18938);
	play (40,18938);
	play (56,18938);
	play (72,18938);
	play (88,18938);
	
	
	
	createenemy (0, 0, 44, ko+240, 0, 0, 0, -1);
	createenemy (0, 0, 44, ko+260, 0, 0, 0, 1);
	ee (0, 0, 49, ko+200);
	ee (0, 0, 49, ko+200);
	ee (0, 0, 43, ko+200);
	}
	
	}
	
	
	
	if (P==4)
	{
	
	OffsetRect(&boundsB[7], 170, 130);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	
	SetRect (&boundsB[23], 320-bild2, 240-bild3, 320+bild4, 240+bild5);
	DrawPicture(Pic[23], &boundsB[23]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1, 240-bild3*bC2, 320-1+bild4*bC3, 240+bild5*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1*bC1, 240-bild3*bC2*bC2, 320-1+bild4*bC3*bC3, 240+bild5*bC4*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	bild+=32;
	
	OffsetRect(&boundsB[4], 0, +bild);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	OffsetRect(&boundsB[5], 0, -428+bild);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	if (bild>=908)
	{
	P++;
	}
	
	}
	
	if (P==5)
	{
	
	
	bild2+=4;
	bild3+=3;
	bild4+=4;
	bild5+=3;
	
	
	if (bild2>=421)
	{
	bild2=320;
	bild3=240;
	bild4=320;
	bild5=240;
	}
	
	OffsetRect(&boundsB[7], 170, 130);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	
	SetRect (&boundsB[23], 320-bild2, 240-bild3, 320+bild4, 240+bild5);
	DrawPicture(Pic[23], &boundsB[23]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1, 240-bild3*bC2, 320-1+bild4*bC3, 240+bild5*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1*bC1, 240-bild3*bC2*bC2, 320-1+bild4*bC3*bC3, 240+bild5*bC4*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	
	}
	
	
	if (P==6)
	{
	
	
	bild2+=8*bild2/320;
	bild3+=6*bild3/240;
	bild4+=8*bild2/320;
	bild5+=6*bild3/240;

	
	SetRect (&boundsB[7], 0, 0, 640, 480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	
	SetRect (&boundsB[23], 320-bild2, 240-bild3, 320+bild4, 240+bild5);
	DrawPicture(Pic[23], &boundsB[23]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1, 240-bild3*bC2, 320-1+bild4*bC3, 240+bild5*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[24], 320-1-bild2*bC1*bC1, 240-bild3*bC2*bC2, 320-1+bild4*bC3*bC3, 240+bild5*bC4*bC4);
	DrawPicture(Pic[24], &boundsB[24]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	SetRect (&boundsB[26], 320-1-bild2*bC1*bC1*bC1*bC1*bC1*bC1*bC1, 240-bild3*bC2*bC2*bC2*bC2*bC2*bC2*bC2, 320-1+bild4*bC3*bC3*bC3*bC3*bC3*bC3*bC3, 240+bild5*bC4*bC4*bC4*bC4*bC4*bC4*bC4);
	DrawPicture(Pic[26], &boundsB[26]);
	
	if (320-bild2*bC1*bC1*bC1*bC1*bC1*bC1*bC1<-200)
	{
	P++;
	ee (320,140, 50, ko+270);
	bC5=0;
	DaLoadFile (173);
	stopsound ();
	Pic[7] = GetPicture(1609);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);
	play (40, 9541);
	}
	}
	
	if (P==7)
	{
	if (bC5++==270)
	{
	snd5=(int)TickCount();
	damianIgnoriertFehler = AS_PlayID (14151, nil);
	}
	
	
	if (bC5>=300)
	{
	if (GS<500)
	{
	if ((int)TickCount()-snd5>=2560)
	{
	snd5=(int)TickCount();
	damianIgnoriertFehler = AS_PlayID (14151, nil);
	}
	}
	}
	
	if (bC5>220)
	{
	SetRect (&boundsB[7], 0, 0, 640, 480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	
	if (bC5<50)
	{
	SetRect (&boundsB[7], 0, 0, 640, 480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	
	if (bC5<=220)
	{
	if (bC5>=50)
	{
	if (rd>=40)
	{
	SetRect (&boundsB[7], 0, 0, 640, 480);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	if (rd<40)
	{
	SetRect (&boundsB[9], 0, 0, 640, 480);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	}
	}
	}
	
	}
	
	
	
	}
	
	
	
	/*L7 Wasser--------------------------------------*/
	
	if (L==7)
	{
	if (P==0)
	{
	reset ();
	
	DaLoadFile (151);
	damianIgnoriertFehler = AS_PlayID (51, nil);
	
	
	Pic[1] = GetPicture(801);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(802);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(803);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(804);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(805);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(806);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);
	
	Pic[7] = GetPicture(807);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);
	
	Pic[8] = GetPicture(808);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);
	
	Pic[9] = GetPicture(809);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);
	
	Pic[10] = GetPicture(622);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[11] = GetPicture(1511);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1509);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1512);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1513);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	PicVG[2] = GetPicture(800);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	PicVG[5] = GetPicture(841);
	boundsVG[5] = ((**PicVG[5]).picFrame);
	OboundsVG[5] = ((**PicVG[5]).picFrame);
	
	PicVG[6] = GetPicture(842);
	boundsVG[6] = ((**PicVG[6]).picFrame);
	OboundsVG[6] = ((**PicVG[6]).picFrame);
	
	PicVG[7] = GetPicture(840);
	boundsVG[7] = ((**PicVG[7]).picFrame);
	OboundsVG[7] = ((**PicVG[7]).picFrame);
	
	Pic[23] = GetPicture(811);
	boundsB[23] = ((**Pic[23]).picFrame);
	OboundsB[23] = ((**Pic[23]).picFrame);
	
	Pic[24] = GetPicture(812);
	boundsB[24] = ((**Pic[24]).picFrame);
	OboundsB[24] = ((**Pic[24]).picFrame);
	
	Pic[25] = GetPicture(813);
	boundsB[25] = ((**Pic[25]).picFrame);
	OboundsB[25] = ((**Pic[25]).picFrame);
	
	Pic[26] = GetPicture(814);
	boundsB[26] = ((**Pic[26]).picFrame);
	OboundsB[26] = ((**Pic[26]).picFrame);
	
	Pic[27] = GetPicture(815);
	boundsB[27] = ((**Pic[27]).picFrame);
	OboundsB[27] = ((**Pic[27]).picFrame);
	
	Pic[28] = GetPicture(816);
	boundsB[28] = ((**Pic[28]).picFrame);
	OboundsB[28] = ((**Pic[28]).picFrame);
	
	Pic[29] = GetPicture(817);
	boundsB[29] = ((**Pic[29]).picFrame);
	OboundsB[29] = ((**Pic[29]).picFrame);
	
	Pic[30] = GetPicture(824);
	boundsB[30] = ((**Pic[30]).picFrame);
	OboundsB[30] = ((**Pic[30]).picFrame);
	
	Pic[31] = GetPicture(830);
	boundsB[31] = ((**Pic[31]).picFrame);
	OboundsB[31] = ((**Pic[31]).picFrame);
	
	Pic[32] = GetPicture(821);
	boundsB[32] = ((**Pic[32]).picFrame);
	OboundsB[32] = ((**Pic[32]).picFrame);
	
	Pic[33] = GetPicture(822);
	boundsB[33] = ((**Pic[33]).picFrame);
	OboundsB[33] = ((**Pic[33]).picFrame);
	
	Pic[34] = GetPicture(823);
	boundsB[34] = ((**Pic[34]).picFrame);
	OboundsB[34] = ((**Pic[34]).picFrame);
	
	
	HX[0]=-100;
	HY[0]=200;
	
	HX[1]=-100;
	HY[1]=300;
	
	LT=1;
	
	FPS=4;
	ko=0;
	p=0;
	bild2=0;
	text (0, 40, 320, 240, 2);
	SB++;
	Held=1;
	bC=10;
	bC1=100;
	bild7=400;
	P=1;
	
	snd5=(int)TickCount();
	snd4=0;
	
	/*Gegner*/
	
	ee(-300, 480, 56, 1300); /*(BOSS)*/
	
	
	ee(6*rd4, 480, 54, 60);
	ee(400, 480, 54, 130);
	ee(300, 480, 54, 130);
	ee(500, 480, 54, 130);
	ee(150, 480, 54, 200);
	ee(250, 480, 54, 200);
	ee(50, 480, 54, 200);
	ee(620, 480, 54, 200);
	ee(50, 480, 54, 250);
	ee(100, 480, 54, 275);
	ee(150, 480, 54, 300);
	ee(250, 480, 54, 350);
	ee(300, 480, 54, 375);
	ee(350, 480, 54, 400);
	ee(450, 480, 54, 450);
	ee(500, 480, 54, 475);
	ee(600, 480, 54, 525);
	ee(200, 480, 55, 550);
	ee(600, 480, 55, 575);
	ee(50, 480, 54, 600);
	ee(600, 480, 54, 625);
	
	ee(50, 480, 54, 720);
	ee(100, 480, 54, 760);
	ee(150, 480, 54, 800);
	ee(200, 480, 54, 840);
	ee(260, 480, 54, 920);
	ee(390, 480, 54, 920);
	ee(450, 480, 54, 840);
	ee(500, 480, 54, 800);
	ee(550, 480, 54, 760);
	ee(600, 480, 54, 720);
	
	/*ee (0, 290, 60, 0);*/
	/*ee(-50, 270, 60, 2000);*/
	/*P=2 ;*/
	/*ko=2000;*/
	}
	
	if (P==-10)
	{
	ko++;
	FPS=2;
	if (C<3)
	{
	OffsetRect(&boundsB[32+C], 0, bC2-50+0.5*bC1);		
	DrawPicture(Pic[32+C], &boundsB[32+C]);
	boundsB[32+C] = OboundsB[32+C];
	}
	
	if (C==3)
	{
	OffsetRect(&boundsB[30], 0, bC2-50+0.5*bC1);		
	DrawPicture(Pic[30], &boundsB[30]);
	boundsB[30] = OboundsB[30];
	}
	
	OffsetRect(&boundsB[31], 0, 0);		
	DrawPicture(Pic[31], &boundsB[31]);
	boundsB[31] = OboundsB[31];
	
	if (bild7>400)
	{
	bild7-=3;
	}
	
	}
	
	if (P>=1)
	{
	snd4+=FPS;
	if ((int)TickCount()-snd5>snd4)
	{
	ko++;
	bild+=bC/10;
	bild2-=bC*3.2;
	bild3-=bC*3.2*0.76;
	bild4-=bC*3.2*0.76*0.76;
	bild5-=bC*3.2*0.76*0.76*0.76;
	bild6-=bC*3.2*0.76*0.76*0.76*0.76;
	bild7-=bC*3.2*0.76*0.76*0.76*0.76*0.76;
	bild8-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76;
	bild9-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76*0.76;
	bild0-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76*0.76*0.76;
	GS=2;
	}
	
	
	
	
	bild+=bC/10;
	bild2-=bC*3.2;
	bild3-=bC*3.2*0.76;
	bild4-=bC*3.2*0.76*0.76;
	bild5-=bC*3.2*0.76*0.76*0.76;
	bild6-=bC*3.2*0.76*0.76*0.76*0.76;
	bild7-=bC*3.2*0.76*0.76*0.76*0.76*0.76;
	bild8-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76;
	bild9-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76*0.76;
	bild0-=bC*3.2*0.76*0.76*0.76*0.76*0.76*0.76*0.76*0.76;
	
	if (HY[0]>225+bC2+(bC1*1.92))
	{
	if (HY[0]<265+bC2+(bC1*1.92))
	{ 
	if (C0==0)
	{
	createenemy(HX[0], HY[0]+20, 53, -0, (60-rd)/4, (20-rd2)*0.18, -13, 15);
	}
	}
	}
	
	
	/*if (C+C4+C16==0)
	{
	createenemy(220, 330, 52, -3, -8, -5, 0, 12);
	createenemy(220, 450, 52, -3, -8, -5, 0, 12);
	createenemy(220, 290, 52, -3, -8, -5, 0, 12);
	createenemy(220, 170, 52, -3, -8, -5, 0, 12);
	createenemy(220, 210, 52, -3, -8, -5, 0, 12);
	createenemy(220, 250, 52, -3, -8, -5, 0, 12);
	createenemy(220, 370, 52, -3, -8, -5, 0, 12);
	createenemy(220, 410, 52, -3, -8, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 8, -5, 0, 12);
	createenemy(250, 450, 52, -3, 8, -5, 0, 12);
	createenemy(250, 290, 52, -3, 8, -5, 0, 12);
	createenemy(250, 170, 52, -3, 8, -5, 0, 12);
	createenemy(250, 210, 52, -3, 8, -5, 0, 12);
	createenemy(250, 250, 52, -3, 8, -5, 0, 12);
	createenemy(250, 370, 52, -3, 8, -5, 0, 12);
	createenemy(250, 410, 52, -3, 8, -5, 0, 12);
	
	createenemy(220, 330, 52, -3, -5, -5, 0, 12);
	createenemy(220, 450, 52, -3, -5, -5, 0, 12);
	createenemy(220, 290, 52, -3, -5, -5, 0, 12);
	createenemy(220, 170, 52, -3, -5, -5, 0, 12);
	createenemy(220, 210, 52, -3, -5, -5, 0, 12);
	createenemy(220, 250, 52, -3, -5, -5, 0, 12);
	createenemy(220, 370, 52, -3, -5, -5, 0, 12);
	createenemy(220, 410, 52, -3, -5, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 5, -5, 0, 12);
	createenemy(250, 450, 52, -3, 5, -5, 0, 12);
	createenemy(250, 290, 52, -3, 5, -5, 0, 12);
	createenemy(250, 170, 52, -3, 5, -5, 0, 12);
	createenemy(250, 210, 52, -3, 5, -5, 0, 12);
	createenemy(250, 250, 52, -3, 5, -5, 0, 12);
	createenemy(250, 370, 52, -3, 5, -5, 0, 12);
	createenemy(250, 410, 52, -3, 5, -5, 0, 12);
	
	createenemy(220, 330, 52, -3, -2, -5, 0, 12);
	createenemy(220, 450, 52, -3, -2, -5, 0, 12);
	createenemy(220, 290, 52, -3, -2, -5, 0, 12);
	createenemy(220, 170, 52, -3, -2, -5, 0, 12);
	createenemy(220, 210, 52, -3, -2, -5, 0, 12);
	createenemy(220, 250, 52, -3, -2, -5, 0, 12);
	createenemy(220, 370, 52, -3, -2, -5, 0, 12);
	createenemy(220, 410, 52, -3, -2, -5, 0, 12);
	
	createenemy(250, 330, 52, -3, 2, -5, 0, 12);
	createenemy(250, 450, 52, -3, 2, -5, 0, 12);
	createenemy(250, 290, 52, -3, 2, -5, 0, 12);
	createenemy(250, 170, 52, -3, 2, -5, 0, 12);
	createenemy(250, 210, 52, -3, 2, -5, 0, 12);
	createenemy(250, 250, 52, -3, 2, -5, 0, 12);
	createenemy(250, 370, 52, -3, 2, -5, 0, 12);
	createenemy(250, 410, 52, -3, 2, -5, 0, 12);
	}*/
	
	ko++;
	
	if (bild>=640)
	{
	bild-=640;
	p++;
	}
	
	if (bild2<=-640)
	{
	bild2+=640;
	}
	
	if (bild3<=-544)
	{
	bild3+=544;
	}
	
	if (bild4<=-462)
	{
	bild4+=462;
	}
	
	if (bild5<=-393)
	{
	bild5+=393;
	}
	
	if (bild6<=-334)
	{
	bild6+=334;
	}
	
	if (bild7<=-284)
	{
	bild7+=284;
	}
	
	if (bild8<=-241)
	{
	bild8+=241;
	}
	
	if (bild9<=-205)
	{
	bild9+=205;
	}
	
	if (bild0<=-170)
	{
	bild0+=170;
	}
	
	/*Wasser*/
	
	if (bC1<95)
	{	
	DrawPicture(Pic[31], &boundsB[31]);
	}
	
	
	/*Berge*/
	
	if (bC1>-95)
	{
	if (P==1)
	{
	OffsetRect(&boundsB[p+23], -bild, bC2-50+0.5*bC1);		
	DrawPicture(Pic[p+23], &boundsB[p+23]);
	boundsB[p+23] = OboundsB[p+23];
	
	OffsetRect(&boundsB[p+24], 640-bild, bC2-50+0.5*bC1);		
	DrawPicture(Pic[p+24], &boundsB[p+24]);
	boundsB[p+24] = OboundsB[p+24];
	}
	
	if (P==2)
	{
	if (C<3)
	{
	OffsetRect(&boundsB[32+C], 0, bC2-50+0.5*bC1);		
	DrawPicture(Pic[32+C], &boundsB[32+C]);
	boundsB[32+C] = OboundsB[32+C];
	}
	
	if (C==3)
	{
	OffsetRect(&boundsB[30], 0, bC2-50+0.5*bC1);		
	DrawPicture(Pic[30], &boundsB[30]);
	boundsB[30] = OboundsB[30];
	}
	}
	
	}
	
	
	/*if (ko>800)
	{
	if (bC1>-96)
	{
	bC1--;
	if (bC2>-80)
	{
	if (bC1<40)
	{
	bC2--;
	}
	}
	}
	}*/
	
	/* EBENENEN*/
	
	
	/*9.*/
	
	if (bild0<=-40)
	{
	OffsetRect(&boundsB[9], bild0+680, bC2+240+bC1*0.51);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	}
	
	OffsetRect(&boundsB[9], bild0, bC2+240+bC1*0.51);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[9], bild0+170, bC2+240+bC1*0.51);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[9], bild0+340, bC2+240+bC1*0.51);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	OffsetRect(&boundsB[9], bild0+510, bC2+240+bC1*0.51);		
	DrawPicture(Pic[9], &boundsB[9]);
	boundsB[9] = OboundsB[9];
	
	/*8.*/
	
	if (bild9<=-180)
	{
	OffsetRect(&boundsB[8], bild9+820, bC2+240+bC1*0.63);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	}
	
	OffsetRect(&boundsB[8], bild9, bC2+240+bC1*0.63);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	
	OffsetRect(&boundsB[8], bild9+205, bC2+240+bC1*0.63);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	
	OffsetRect(&boundsB[8], bild9+410, bC2+240+bC1*0.63);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	
	OffsetRect(&boundsB[8], bild9+615, bC2+240+bC1*0.63);		
	DrawPicture(Pic[8], &boundsB[8]);
	boundsB[8] = OboundsB[8];
	
	/*7.*/
	
	
	OffsetRect(&boundsB[7], bild8, bC2+240+bC1*0.77);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	OffsetRect(&boundsB[7], bild8+241, bC2+240+bC1*0.77);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	OffsetRect(&boundsB[7], bild8+482, bC2+240+bC1*0.77);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	
	if (bild8<=-83)
	{
	OffsetRect(&boundsB[7], bild8+723, bC2+240+bC1*0.77);		
	DrawPicture(Pic[7], &boundsB[7]);
	boundsB[7] = OboundsB[7];
	}
	
	/*6.*/
	
	OffsetRect(&boundsB[6], bild7, bC2+240+bC1*0.92);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], bild7+284, bC2+240+bC1*0.92);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	OffsetRect(&boundsB[6], bild7+568, bC2+240+bC1*0.92);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	
	if (bild7<=-212)
	{
	OffsetRect(&boundsB[6], bild7+852, bC2+240+bC1*0.92);		
	DrawPicture(Pic[6], &boundsB[6]);
	boundsB[6] = OboundsB[6];
	}
	
	
	/*5.*/
	
	OffsetRect(&boundsB[5], bild6+668, bC2+240+bC1*1.08);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	OffsetRect(&boundsB[5], bild6, bC2+240+bC1*1.08);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	OffsetRect(&boundsB[5], bild6+334,  bC2+240+bC1*1.08);		
	DrawPicture(Pic[5], &boundsB[5]);
	boundsB[5] = OboundsB[5];
	
	
	/*4.*/
	
	OffsetRect(&boundsB[4], bild5+393, bC2+240+bC1*1.26);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	OffsetRect(&boundsB[4], bild5, bC2+240+bC1*1.26);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	
	if (bild5<=-146)
	{
	OffsetRect(&boundsB[4], bild5+786, bC2+240+bC1*1.26);		
	DrawPicture(Pic[4], &boundsB[4]);
	boundsB[4] = OboundsB[4];
	}
	
	
	/*3.*/
	
	OffsetRect(&boundsB[3], bild4+462, bC2+240+bC1*1.43);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	OffsetRect(&boundsB[3], bild4, bC2+240+bC1*1.43);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	
	
	if (bild4<=-284)
	{
	OffsetRect(&boundsB[3], bild4+924, bC2+240+bC1*1.43);		
	DrawPicture(Pic[3], &boundsB[3]);
	boundsB[3] = OboundsB[3];
	}
	
	
	/*2.*/
	
	OffsetRect(&boundsB[2], bild3+544, bC2+240+bC1*1.7);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	OffsetRect(&boundsB[2], bild3, bC2+240+bC1*1.7);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	
	if (bild3<=-448)
	{
	OffsetRect(&boundsB[2], bild3+1088, bC2+240+bC1*1.7);		
	DrawPicture(Pic[2], &boundsB[2]);
	boundsB[2] = OboundsB[2];
	}
	
	
	/*1.*/
	
	OffsetRect(&boundsB[1], bild2, bC2+240+bC1*1.95);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	OffsetRect(&boundsB[1], 640+bild2, bC2+240+bC1*1.95);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	
	
	
	
	
	
	
	}
	}
	
	
	
	/*L9---------------------------------------------*/
	
	if (L==9)
	{
	
	ko++;
	
	if (ko>=4800)
	{
	stopsound ();
	L=-1;
	P=0;
	}
	
	if (bC!=51)
	{	
	DrawPicture(Pic[8], &boundsB[8]);
	}
	
	if (bC==51)
	{
	if (C0==0)
	{
	DrawPicture(Pic[8], &boundsB[8]);
	}
	}
	
	if (bC==51)
	{
	if (C0)
	{
	DrawPicture(Pic[19], &boundsB[19]);
	}
	}
	}
	
	
	
	
	
	
	/*GAME OVER-----------------------------*/
	
	if (L==10)
	{
	ko++;
	FPS=3;
	
	if (ko>20)
	{
	p++;
	ko=0;
	}
	DrawPicture(Pic[15], &boundsB[15]);
	
	OffsetRect(&boundsB[1], 140, 100);		
	DrawPicture(Pic[1], &boundsB[1]);
	boundsB[1] = OboundsB[1];
	
	if (ko>0)
	{
	OffsetRect(&boundsB[2+p], 290, 240);		
	DrawPicture(Pic[2+p], &boundsB[2+p]);
	boundsB[2+p] = OboundsB[2+p];
	}
	
	if (p>=10)
	{
	DrawPicture(Pic[12], &boundsB[12]);
	}
	
	if (p>15)
	{
	L=-1;
	P=0;
	p=0;
	stopsound();
	}
	
	if (p<10)
	{
	if (START)
	{
	L=L2;
	if (L==0)
	{
	P=-2;
	Pic[1] = GetPicture(11);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(12);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(303);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(304);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(305);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[6] = GetPicture(306);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);	
	
	Pic[10] = GetPicture(1501);
	boundsB[10] = ((**Pic[10]).picFrame);
	OboundsB[10] = ((**Pic[10]).picFrame);
	
	Pic[11] = GetPicture(1502);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1503);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1504);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1505);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	Pic[15] = GetPicture(14);
	boundsB[15] = ((**Pic[15]).picFrame);
	OboundsB[15] = ((**Pic[15]).picFrame);
	
	Pic[20] = GetPicture(131);
	boundsB[20] = ((**Pic[20]).picFrame);
	OboundsB[20] = ((**Pic[20]).picFrame);
	
	Pic[21] = GetPicture(132);
	boundsB[21] = ((**Pic[21]).picFrame);
	OboundsB[21] = ((**Pic[21]).picFrame);
	
	PicVG[0] = GetPicture(1601);
	boundsVG[0] = ((**PicVG[0]).picFrame);
	OboundsVG[0] = ((**PicVG[0]).picFrame);
	
	PicVG[1] = GetPicture(1602);
	boundsVG[1] = ((**PicVG[1]).picFrame);
	OboundsVG[1] = ((**PicVG[1]).picFrame);
	
	PicVG[2] = GetPicture(300);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	PicVG[3] = GetPicture(13);
	boundsVG[3] = ((**PicVG[3]).picFrame);
	OboundsVG[3] = ((**PicVG[3]).picFrame);
	
	PicVG[4] = GetPicture(15);
	boundsVG[4] = ((**PicVG[4]).picFrame);
	OboundsVG[4] = ((**PicVG[4]).picFrame);
	
	PicVG[5] = GetPicture(16);
	boundsVG[5] = ((**PicVG[5]).picFrame);
	OboundsVG[5] = ((**PicVG[5]).picFrame);
	
	PicVG[6] = GetPicture(17);
	boundsVG[6] = ((**PicVG[6]).picFrame);
	OboundsVG[6] = ((**PicVG[6]).picFrame);
	
	PicVG[8] = GetPicture(1521);
	boundsVG[8] = ((**PicVG[8]).picFrame);
	OboundsVG[8] = ((**PicVG[8]).picFrame);
	
	PicVG[9] = GetPicture(1522);
	boundsVG[9] = ((**PicVG[9]).picFrame);
	OboundsVG[9] = ((**PicVG[9]).picFrame);
	
	PicVG[10] = GetPicture(1523);
	boundsVG[10] = ((**PicVG[10]).picFrame);
	OboundsVG[10] = ((**PicVG[10]).picFrame);
	
	PicVG[11] = GetPicture(1524);
	boundsVG[11] = ((**PicVG[11]).picFrame);
	OboundsVG[11] = ((**PicVG[11]).picFrame);
	
	PicVG[12] = GetPicture(1525);
	boundsVG[12] = ((**PicVG[12]).picFrame);
	OboundsVG[12] = ((**PicVG[12]).picFrame);
	
	ko=0;
	P=-2;
	p=1;
	bild=0;
	HY[0]=430;
	HX[0]=330;
	HY[1]=430;
	HX[1]=270;
	HeldSz=0.4;
	stopsound();
	     
	}
	
	if (L==2)
	{
   	L =1;
	}
	
	if (L==4)
	{
	L=3;
	}
	
	if (L==5)
	{
	P=0;
	
	Pic[1] = GetPicture(501);
	boundsB[1] = ((**Pic[1]).picFrame);
	OboundsB[1] = ((**Pic[1]).picFrame);
	
	Pic[2] = GetPicture(511);
	boundsB[2] = ((**Pic[2]).picFrame);
	OboundsB[2] = ((**Pic[2]).picFrame);
	
	Pic[3] = GetPicture(512);
	boundsB[3] = ((**Pic[3]).picFrame);
	OboundsB[3] = ((**Pic[3]).picFrame);
	
	Pic[4] = GetPicture(513);
	boundsB[4] = ((**Pic[4]).picFrame);
	OboundsB[4] = ((**Pic[4]).picFrame);
	
	Pic[5] = GetPicture(514);
	boundsB[5] = ((**Pic[5]).picFrame);
	OboundsB[5] = ((**Pic[5]).picFrame);
	
	Pic[0] = GetPicture(515);
	boundsB[0] = ((**Pic[0]).picFrame);
	OboundsB[0] = ((**Pic[0]).picFrame);
	
	Pic[6] = GetPicture(522);
	boundsB[6] = ((**Pic[6]).picFrame);
	OboundsB[6] = ((**Pic[6]).picFrame);	
	
	Pic[7] = GetPicture(523);
	boundsB[7] = ((**Pic[7]).picFrame);
	OboundsB[7] = ((**Pic[7]).picFrame);	
	
	Pic[8] = GetPicture(524);
	boundsB[8] = ((**Pic[8]).picFrame);
	OboundsB[8] = ((**Pic[8]).picFrame);	
	
	Pic[9] = GetPicture(525);
	boundsB[9] = ((**Pic[9]).picFrame);
	OboundsB[9] = ((**Pic[9]).picFrame);	
	
	Pic[11] = GetPicture(1502);
	boundsB[11] = ((**Pic[11]).picFrame);
	OboundsB[11] = ((**Pic[11]).picFrame);
	
	Pic[12] = GetPicture(1503);
	boundsB[12] = ((**Pic[12]).picFrame);
	OboundsB[12] = ((**Pic[12]).picFrame);
	
	Pic[13] = GetPicture(1504);
	boundsB[13] = ((**Pic[13]).picFrame);
	OboundsB[13] = ((**Pic[13]).picFrame);
	
	Pic[14] = GetPicture(1505);
	boundsB[14] = ((**Pic[14]).picFrame);
	OboundsB[14] = ((**Pic[14]).picFrame);
	
	Pic[15] = GetPicture(1603);
	boundsB[15] = ((**Pic[15]).picFrame);
	OboundsB[15] = ((**Pic[15]).picFrame);
	
	PicVG[2] = GetPicture(500);
	boundsVG[2] = ((**PicVG[2]).picFrame);
	OboundsVG[2] = ((**PicVG[2]).picFrame);
	
	}
	
	
	if (L==6)
	{
	P=0;
	}
	
	}
	}
	}
	/*ENDE HINTERGRUENDE*/
	
	
	
	
	
	
	
	
	gameover ();
	
	/*Procedures der einzelnen Sprites*/
	
	if (P2)
	{
	
	if (rd<=10)
	{
	if (PSW==0)
	{
	PSW=1;
	}
	}
	
	if (rd>=90)
	{
	if (PSW==1)
	{
	PSW=0;
	}
	}
	
	HeldX=HX[PSW];
	HeldY=HY[PSW];
	}
	
	if (P2==0)
	{
	HeldX=HX[0];
	HeldY=HY[0];
	}

	for (me=0;me<128;me++)	
	{
		moveenemy (me);
	}
	
 	for (me=0; me<128; me++)
	{
	if (GSz[me]<1)
	{
	if (G[me]>1)
	{
	h1=(((OboundsS[GP[me]].right)-(OboundsS[GP[me]].left)));
	h2=(((OboundsS[GP[me]].bottom)-(OboundsS[GP[me]].top)));
	SetRect (&boundsS[GP[me]], 0, 0, ((GSz[me]*h1)), ((GSz[me]*h2)));
	
	OffsetRect(&boundsS[GP[me]], (GX[me]+((((boundsS[GP[me]]).left)-((boundsS[GP[me]]).right)/2))), (short)(GY[me]+(((boundsS[GP[me]]).top)-((boundsS[GP[me]]).bottom)/2)));
	DrawPicture(Sprite[GP[me]], &boundsS[GP[me]]);	
	boundsS[GP[me]]=OboundsS[GP[me]];
	}
	}
	}

 	drawhero();

 	drawshot (0);
 	
 	draw ();
	
	
	/*Zeichnen*/
	
	bg ();
	
	/*Gegner Zeichnen*/

	for (me=0; me<128; me++)
	{
	if (GSz[me]>=1)
	{
	if (G[me]>1)
	{
	h1=(((OboundsS[GP[me]].right)-(OboundsS[GP[me]].left)));
	h2=(((OboundsS[GP[me]].bottom)-(OboundsS[GP[me]].top)));
	SetRect (&boundsS[GP[me]], 0, 0, ((GSz[me]*h1)), ((GSz[me]*h2)));
	
	OffsetRect(&boundsS[GP[me]], (GX[me]+((((boundsS[GP[me]]).left)-((boundsS[GP[me]]).right)/2))), (short)(GY[me]+(((boundsS[GP[me]]).top)-((boundsS[GP[me]]).bottom)/2)));
	DrawPicture(Sprite[GP[me]], &boundsS[GP[me]]);	
	boundsS[GP[me]]=OboundsS[GP[me]];
	}
	}
	}
	/*Explosionen Zeichnen*/
	
	for (e=79; e>=0; e--)
	{
	if (E[e]>=0)
	{
	Help[e]++;
	
	exXp[e]+=exSXp[e];
	exYp[e]+=exSYp[e];
	
	h1=(((OExbounds[exAcount[e]+(exTp[e]*10)].right)-(OExbounds[exAcount[e]+(exTp[e]*10)].left)));
	h2=(((OExbounds[exAcount[e]+(exTp[e]*10)].bottom)-(OExbounds[exAcount[e]+(exTp[e]*10)].top)));

	SetRect (&Exbounds[exAcount[e]+exTp[e]*10], 0, 0, (exsizep[e]*h1), (exsizep[e]*h2));
	OffsetRect(&Exbounds[exAcount[e]+(exTp[e]*10)], exXp[e]+(((Exbounds[exAcount[e]+(exTp[e]*10)]).left)-((Exbounds[exAcount[e]+(exTp[e]*10)]).right)/2), exYp[e]+(-((Exbounds[exAcount[e]+(exTp[e]*10)]).bottom)+((Exbounds[count+(exTp[e]*10)]).top))/2);
	DrawPicture(Ex[exAcount[e]+exTp[e]*10], &Exbounds[exAcount[e]+exTp[e]*10]);
	
	if (Help[e]>=exSp[e])
	{
	exAcount[e]++;
	Help[e]=0;
	}
	
	if (exAcount[e]>=pcp[e])
	{
	exAcount[e]=0;
	E[e]=-1;
	}
	}
	}
	
	/* Fire */
	
	shot (0);
	 	
	/*Sch�sse zeichnen*/
	
	
	for (ds=0; ds<150; ds++)
	{
		drawshot (ds);
	}
	
	
	/*Liste Zeichnen*/
	
	list();
	
	
	/*Text Zeichnen*/
	
	drawtext ();
	
	
	/*Ton abspielen*/
	
	playsound ();
	
	
	/*Zeichnen*/
	
	CopyBits(&((GrafPtr) myGworld)->portBits,&((GrafPtr) dasWindow)->portBits,&oldbounds,&oldbounds,srcCopy,NULL);
	
	test(0);
	}
	}
	
	/*ENDE LOOP*/
	
	SetGWorld(oldWorld,nil);
	LMSetMBarHeight(mBarHeight);
	DiffRgn(GrayRgn, mBarRgn, GrayRgn);
	DisposeRgn(mBarRgn);
	DrawMenuBar();
	AS_CloseDown();	
	while(!Button());
	/*printf("%d/n", HP);*/
	return 0;
}
	
	
	/*ENDE PROGRAMM*/
	
void dobewegen ()
{
GetKeys(myKeyMap);
l = IsKeyDown(myKeyMap, keyArrowLeft);	
if (l>0) {l=1;}
r = IsKeyDown(myKeyMap, keyArrowRight);	
if (r>0) {r=1;}
u = IsKeyDown(myKeyMap, keyArrowUp);	
if (u>0) {u=1;}
d = IsKeyDown(myKeyMap, keyArrowDown);	
if (d>0) {d=1;}
f = IsKeyDown(myKeyMap, keySpace);

START=IsKeyDown(myKeyMap, keyF1);

bu4=IsKeyDown(myKeyMap, keyF9);
if (bu4)
{
LR();
}

bu4= IsKeyDown(myKeyMap, keyF10);

if(bu4)
{
SR();
}


sb = IsKeyDown(myKeyMap, keyReturn);
if (sb==0)
{
sb = IsKeyDown(myKeyMap, keyControl);
}
if (sb==0)
{
sb = IsKeyDown(myKeyMap, keyEnter);
}

if (C==0)
{
}

if (HX[0]>620){r=0;}
if (HX[0]<20){l=0;}
if (HY[0]>440){d=0;}
if (HY[0]<20){u=0;}

if (Held==1)
{
PB++;

if (PB>60)
{
if (f)
{
ee (HX[0], HY[0], 35, 0);
}
}


if (f)
{
PB=0;
}


if (SB)
{
if (sb)
{
createenemy (320, 540, 34, 0, 0, 0, 0, 0);
SB=0;
}
}

if (r+l+u+d==1)
{
if (r)
{
HX[0]+=5*FPS;
}
if (l)
{
HX[0]-=5*FPS;
}
if (u)
{
HY[0]-=5*FPS;
}
if (d)
{
HY[0]+=5*FPS;
}
}

if (r+l+u+d>1)
{
if (r)
{
HX[0]+=3.6*FPS;
}
if (l)
{
HX[0]-=3.6*FPS;
}
if (u)
{
HY[0]-=3.6*FPS;
}
if (d)
{
HY[0]+=3.6*FPS;
}
}
}

}





/*2P---------------------------------------*/

void dobewegenP2 ()
{
GetKeys(myKeyMap);
l2 = IsKeyDown(myKeyMap, keyPad4);	
if (l2>0) {l2=1;}
r2 = IsKeyDown(myKeyMap, keyPad6);	
if (r2>0) {r2=1;}
u2 = IsKeyDown(myKeyMap, keyPad8);	
if (u2>0) {u2=1;}
d2 = IsKeyDown(myKeyMap, keyPad5);	
if (d2>0) {d2=1;}
f2 = IsKeyDown(myKeyMap, keyPad0);







if (C==0)
{
}

if (HX[1]>620){r2=0;}
if (HX[1]<20){l2=0;}
if (HY[1]>440){d2=0;}
if (HY[1]<20){u2=0;}

if (Held==1)
{
PB2++;

if (PB2>60)
{
if (f2)
{
ee (HX[1], HY[1], 35, 0);
}
}


if (f2)
{
PB2=0;
}


if (SB)
{
if (sb)
{
createenemy (320, 540, 34, 0, 0, 0, 0, 0);
SB=0;
}
}

if (r2+l2+u2+d2==1)
{
if (r2)
{
HX[1]+=5*FPS;
}
if (l2)
{
HX[1]-=5*FPS;
}
if (u2)
{
HY[1]-=5*FPS;
}
if (d2)
{
HY[1]+=5*FPS;
}
}

if (r2+l2+u2+d2>1)
{
if (r2)
{
HX[1]+=3.6*FPS;
}
if (l2)
{
HX[1]-=3.6*FPS;
}
if (u2)
{
HY[1]-=3.6*FPS;
}
if (d2)
{
HY[1]+=3.6*FPS;
}
}
}

}



/*Sch�sse Kreieren*/

void createshot (float sX, float sY, float sXS, float sYS, short sS, short sP, short sA)
{
for (cs=0; cs<150; cs++)
{
if (S[cs] == 0)
{
SX[cs]=sX;
SY[cs]=sY;
SXS[cs]=sXS;
SYS[cs]=sYS;
SS[cs]=sS;
SP[cs]=sP;
SA[cs]=sA;
S[cs] = 1;
break;
}
}
}

/*Explosionen Kreieren*/

void createexplosion (short exT, short exX, short exY, short exS, short exSX, short exSY, short pc, float exsize)
{ 

for (e=0; e<80; e++)
{

if (E[e]==-1)
{
exAcount[e]=1;
Help[e]=0;
E[e]=0;
exTp[e]=exT;
exXp[e]=exX;
exYp[e]=exY;
exSp[e]=exS;
exSYp[e]=exSY;
exSXp[e]=exSX;
pcp[e]=pc;
exsizep[e]=exsize;
break;
}
}
}

/*---------------------------------------------------------------------------*/
/*Gegner Kreieren*/

void createenemy (int GXm, int GYm, int GTm, int GAm, short GCm, short GC2m, short GC3m, short GC4m)
{
for (h3=0; h3<128; h3++)
{
if (G[h3] == 0)
{
GX[h3]=GXm;
GY[h3]=GYm;
GT[h3]=GTm;
GA[h3]=GAm;
GC[h3]=GCm;
GC2[h3]=GC2m;
GC3[h3]=GC3m;
GC4[h3]=GC4m;
G[h3]=1;
break;
}
}
}

/*------Gegner bewegen-------*/

void moveenemy (me)

/*Aktiv Check*/
{
if (G[me]==1)
{
if (GA[me]<=ko)
{
G[me]=2;
}
}

/*Verhaltensmuster des Gegners Typ 0 */
if (GT[me]==0)
{
if (G[me]==1)
{

}
if (G[me]==2)
{
GH[me]=100;
GSzX[me]=40;
GSzY[me]=20;
GSz[me]=1;
G[me]=3;
}
if (G[me]==3)
{

GH[me]-=1;

if (GH[me]<0)
{
GH[me]-=5;
GSz[me]=1+0.05*C0;
}
GY[me]+=GC4[me];
GX[me]+=GC3[me];



if (GC3[me]>=2)
{
GP[me]=3;

if (GC[me]++==3)
{
if (GH[me]<60)
{
createexplosion (1, GX[me], GY[me], 1, -20, 2, 14, 1);
}
GC[me]=0;
}

}

if (GC3[me]<=-2)
{
GP[me]=1;

if (GC[me]++==3)
{
if (GH[me]<0)
{
createexplosion (1, GX[me], GY[me], 1, 20, 2, 14, 1);
}
GC[me]=0;
}

}

if (GC3[me]>-2)
{
if (GC3[me]<2)
{
GP[me]=2;

if (GC[me]++==3)
{
if (GH[me]<60)
{
createexplosion (1, GX[me], GY[me], 1, 0, -20, 14, 1);
}
GC[me]=0;
}
}
}

if (GH[me]<=-100)
{
G[me]=4;
}
}

if (G[me]==4)
{
createshot (GX[me], GY[me], 0, 5, 2, 0, 0);
createshot (GX[me], GY[me], 5, 0, 2,0, 0);
createshot (GX[me], GY[me], 0, -5, 2,0, 0);
createshot (GX[me], GY[me], -5, 0, 2,0, 0);
createshot (GX[me], GY[me], 3, 3, 2,0, 0);
createshot (GX[me], GY[me], 3, -3, 2,0, 0);
createshot (GX[me], GY[me], -3, 3, 2,0, 0);
createshot (GX[me], GY[me], -3, -3, 2,0, 0);
createexplosion (0, GX[me], GY[me], 1, 0, 0, 7, 1);
createexplosion (0, GX[me], GY[me], 1, 15, 0, 7, 1);
createexplosion (0, GX[me], GY[me], 1, -15, 0, 7, 1);
createexplosion (0, GX[me], GY[me], 1, 0, 15, 7, 1);
createexplosion (0, GX[me], GY[me], 1, 0, -15, 7, 1);
createexplosion (0, GX[me], GY[me], 1, 10, 10, 7, 1);
createexplosion (0, GX[me], GY[me], 1, 10, -10, 7, 1);
createexplosion (0, GX[me], GY[me], 1, -10, 10, 7, 1);
createexplosion (0, GX[me], GY[me], 1, -10, -10, 7, 1);
damianIgnoriertFehler = AS_PlayID (202, nil);
G[me]=0;
}
}


/*Typ 1----------------------------------------*/

if (GT[me]==1)
{
GSzX[me]=20;
GSzY[me]=40;
if (G[me]==2)
{
G[me]=3;
GSz[me]=0.8;
GH[me]=80;
if (LV==1)
{
GC[me]=16;
}

if (LV==0)
{
GC[me]=10;
}

}
if (G[me]==3)
{
GY[me]+=5+GC4[me];
GX[me]+=GC3[me];
GP[me]=2;
if (GSz[me]<1)
{
GSz[me]+=0.01;
}
if (GH[me]<=0)
{
G[me]++;
}

if (abs(HeldY-GY[me])<30+20*LV)
{
if (GC[me]>0)
{
GC[me]--;
AS_PlayID (558, nil);
createshot (GX[me], GY[me], -8, 0, 2, 0, 0);
createshot (GX[me], GY[me], 8, 0, 2, 0, 0);
}
}
if (GY[me]>550)
{
G[me]=0;
}
}
if (G[me]==4)
{
damianIgnoriertFehler = AS_PlayID (2080, nil);
createexplosion(1, GX[me], GY[me], 1, 0, 0, 14, 2*GSz[me]);
G[me]=0;
}
}


/*Typ 2---------------------------------------*/

if (GT[me]==2)
{

if (G[me]==2)
{
GH[me]=30;
G[me]=3;
GSzX[me]=25;
GSzY[me]=25;
GSz[me]=1;
GC2[me]=0;
}


if (G[me]==3)
{

if (GC2[me]==0)
{
if (LV>=1)
{
GY[me]+=4*FPS;
GX[me]+=GC3[me];
GP[me]=6;
GSY[me]=6*FPS;
}

if (LV==0)
{
GY[me]+=3.2*FPS;
GX[me]+=GC3[me];
GP[me]=6;
GSY[me]=4*FPS;
}

if (GY[me]>HeldY)
{
GSY[me]=0;
if (GX[me]>HeldX)
{
GC2[me]=1;
}
if (GX[me]<HeldX)
{
GC2[me]=2;
}
}
}

if (GC2[me]==1)
{
GP[me]=7;
GX[me]-=(3.2+LV)*FPS;
GSX[me]=(-3.2-LV)*FPS;
}

if (GC2[me]==2)
{
GP[me]=9;
GX[me]+=(3.2+LV)*FPS;
GSX[me]=(3.2+LV)*FPS;
}


if (GH[me]<=0)
{
G[me]++;
}
if (abs(GX[me]-260)>=520)
{
G[me]++;
}
}

if (G[me]==4)
{
damianIgnoriertFehler = AS_PlayID (2080, nil);
createexplosion (1, GX[me], GY[me], 1, GSX[me]/2, GSY[me]/2, 14, GSz[me]);
G[me]=0;
}
}

/*Typ 3---------------------------------------------*/


if (GT[me]==3)
{

if (G[me]==2)
{
GH[me]=90;
G[me]=3;
GSzX[me]=45;
GSzY[me]=45;
GSz[me]=1;
}

if (G[me]==3)
{
GP[me]=26;
if (GC2[me]==0)
{
GY[me]+=3;
GX[me]+=GSX[me];
GC[me]++;
if(GC[me]>20)
{
GC2[me]=1;
GC[me]=0;
}
}

if (GC2[me]==1)
{
if(C==2)
{
damianIgnoriertFehler = AS_PlayID (20361, nil);
createshot (GX[me], GY[me], 0, 9+(4*LV), 3, 8, 0);
GP[me]=27;
if (GC[me]++>=1)
{
GC2[me]=0;
if (HeldX<GX[me])
{
GSX[me]=-5;
}
if (HeldX>GX[me])
{
GSX[me]=5;
}

}
}
}

if (GH[me]<=0)
{
createexplosion (1, GX[me], GY[me], 1, GSX[me]/2, GSY[me]/2, 14, 2*GSz[me]);
G[me]++;
}
if (GY[me]>550)
{
G[me]=0;
}
}

if (G[me]==4)
{
damianIgnoriertFehler = AS_PlayID (2080, nil);
G[me]=0;
}
}


/*Typ4---------------------------------------*/

if (GT[me]==4)
{

if (G[me]==2)
{
GH[me]=50;
G[me]=3;
GSzX[me]=30;
GSzY[me]=30;
GSz[me]=1;
GP[me]=21;
}

if (G[me]==3)
{
GY[me]+=4;
GX[me]+=GSX[me];

GC4[me]++;

if (HeldX<GX[me])
{
GSX[me]--;
}
if (HeldX>GX[me])
{
GSX[me]++;
}
if (abs(HeldX-GX[me])<10)
{
if (GC4[me]>10)
{
damianIgnoriertFehler = AS_PlayID (2170, nil);
createshot (GX[me], GY[me], 0, 10, 3, 2, 0);
GC4[me]=0;
}
}

if (GSX[me]>11+(6*LV))
{
GSX[me]-=2;
}

if (GSX[me]<-(11+(6*LV)))
{
GSX[me]+=2;
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (203, nil);
createexplosion (1, GX[me], GY[me], 1, GSX[me]/2, GSY[me]/2, 14, GSz[me]);
G[me]++;
}
if (GY[me]>550)
{
G[me]=0;
}
}

if (G[me]==4)
{
G[me]=0;
}
}

/*Typ 5---------------------------------------------*/

if (GT[me]==5)
{

if (G[me]==2)
{
GH[me]=400;
G[me]=3;
GSzX[me]=70;
GSzY[me]=70;
GSz[me]=1;
GP[me]=36;
GSY[me]=7;
GSX[me]=0;
}

if (G[me]==3)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];

if (GY[me]>=440)
{
if (GSX[me]==0)
{
GC2[me]=1;
if (HeldX<GX[me])
{
GSX[me]=-7;
GP[me]=37;
}
if (HeldX>=GX[me])
{
GSX[me]=7;
GSY[me]=0;
GP[me]=39;
}
}
}

if (LV)
{
if (GC2[me]==1)
{
if (C+C4==2)
{
createshot (GX[me], GY[me], 0, -8, 6, 5, 0);
}
}

if (GC2[me]==0)
{
if (C+C4==2)
{
if (GX[me]<320)
{
createshot (GX[me], GY[me], 8, 0, 6, 5, 0);
}
if (GX[me]>=320)
{
createshot (GX[me], GY[me], -8, 0, 6, 5, 0);
}
}
}
}


if (LV<=0)
{
if (GC2[me]==1)
{
if (C+C4==0)
{
createshot (GX[me], GY[me], 0, -8, 6, 5, 0);
}
}

if (GC2[me]==0)
{
if (C+C4==0)
{
if (GX[me]<320)
{
createshot (GX[me], GY[me], 8, 0, 6, 5, 0);
}
if (GX[me]>=320)
{
createshot (GX[me], GY[me], -8, 0, 6, 5, 0);
}
}
}
}



if (abs(GX[me]-350)>720)
{
G[me]=0;
}

if (GH[me]<=0)
{
G[me]++;
}

if (GY[me]>570)
{
G[me]=0;
}

}

if (G[me]==4)
{
G[me]=0;
damianIgnoriertFehler = AS_PlayID (5006, nil);
createexplosion (0, GX[me], GY[me], 1, (GSX[me]/2)+5, (GSY[me]/2)+5, 7, 2*GSz[me]);
createexplosion (0, GX[me], GY[me], 1, (GSX[me]/2)-5, (GSY[me]/2)+5, 7, 2*GSz[me]);
createexplosion (0, GX[me], GY[me], 1, (GSX[me]/2)+5, (GSY[me]/2)-5, 7, 2*GSz[me]);
createexplosion (0, GX[me], GY[me], 1, (GSX[me]/2)-5, (GSY[me]/2)-5, 7, 2*GSz[me]);
}

}

/*Typ 6---------------------------------------------*/

if (GT[me]==6)
{

if (G[me]==2)
{
GH[me]=50;
GSzX[me]=35;
GSzY[me]=35;
GSz[me]=1;
GP[me]=20;
GSY[me]=8;
GSX[me]=0;
GY[me]+=GSY[me];
GX[me]+=GSX[me];
GC[me]++;
if(GC[me]>=4)
{
GP[me]=19;
if(GC[me]>=8)
{
G[me]=3;
GC[me]=0;
GP[me]=11;
}
}
}

if (G[me]==3)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];

if (GC[me]++>=25)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(6+4*LV)*(HeldX-GX[me])/bu;
GSY[me]=(6+4*LV)*(HeldY-GY[me])/bu;
GC[me]=0;
if (GSX[me]>=0)
{
if (GSY[me]>=0)
{
if (GSY[me]-GSX[me]>6)
{
GP[me]=11;
}
if (GSY[me]-GSX[me]<-6)
{
GP[me]=14;
}
if (GSY[me]-GSX[me]>=-6)
{
if (GSY[me]-GSX[me]<=6)
{
GP[me]=15;
}
}
}
if (GSY[me]<0)
{
if (-GSY[me]-GSX[me]>6)
{
GP[me]=13;
}
if (-GSY[me]-GSX[me]<-6)
{
GP[me]=14;
}
if (GSY[me]-GSX[me]>=-6)
{
if (GSY[me]-GSX[me]<=6)
{
GP[me]=18;
}
}
}
}

if (GSX[me]<0)
{
if (GSY[me]>0)
{
if (-GSY[me]+GSX[me]>6)
{
GP[me]=11;
}
if (-GSY[me]+GSX[me]<-6)
{
GP[me]=12;
}
if (-GSY[me]+GSX[me]>=-6)
{
if (-GSY[me]+GSX[me]<=6)
{
GP[me]=16;
}
}
}
if (GSY[me]<=0)
{
if (GSY[me]+GSX[me]>6)
{
GP[me]=13;
}
if (GSY[me]+GSX[me]<-6)
{
GP[me]=12;
}
if (GSY[me]+GSX[me]>=-6)
{
if (GSY[me]+GSX[me]<=6)
{
GP[me]=17;
}
}
}
}
}

if (GH[me]<=0)
{
G[me]++;
}
}

if (G[me]==4)
{
G[me]=0;
damianIgnoriertFehler = AS_PlayID (2080, nil);
createexplosion (1, GX[me], GY[me], 1, GSX[me]/2, GSX[me]/2, 15, GSz[me]);
}
}

/*Typ 7*/

if (GT[me]==7)
{

if (G[me]==2)
{
GH[me]=100;
GSzX[me]=50;
GSzY[me]=40;
GSz[me]=0.75;
GP[me]=51;
GSY[me]=GC2[me];
GSX[me]=GC[me];
GY[me]+=GSY[me];
GX[me]+=GSX[me];
G[me]++;
}

if (G[me]==3)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];

if (GC[me]++>=15)
{
damianIgnoriertFehler = AS_PlayID (29574, nil);
createshot (GX[me]-10, GY[me]+15, -8+GC3[me], GC4[me], 3, 0, 0);
GC[me]=0;
}

if (GH[me]<=0)
{
G[me]++;
GP[me]=53;
damianIgnoriertFehler = AS_PlayID (2080, nil);
}

if (GX[me]<=-50)
{
G[me]=0;
}
if (abs(240-GY[me])>=260)
{
G[me]=0;
}
}

if (G[me]==4)
{

if (C==0)
{

}
createexplosion (5, GX[me]+10*C-15, GY[me], 2, 0, 0, 6, GSz[me]);
GY[me]+=8;
if (GY[me]>500)
{
G[me]=0;
}
}
}


/*Typ 8*/

if (GT[me]==8)
{

if (G[me]==2)
{
GH[me]=300;
GSzX[me]=60;
GSzY[me]=60;
GSz[me]=0.75;
GP[me]=56;
GSY[me]=GC2[me];
GSX[me]=GC[me];
GY[me]+=GSY[me];
GX[me]+=GSX[me];
G[me]++;
}

if (G[me]==3)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];

if (GC[me]++>=15-7*LV)
{
damianIgnoriertFehler = AS_PlayID (1260, nil);
searchshot (GX[me]+50, GY[me], 9, 14, 1, 0);
GC[me]=0;
}

if (GH[me]<=0)
{
G[me]++;
}

if (GX[me]<=-50)
{
G[me]=0;
}
if (abs(240-GY[me])>=260)
{
G[me]=0;
}
}

if (G[me]==4)
{
if (C==0)
{
damianIgnoriertFehler = AS_PlayID (2080, nil);
}
createexplosion (5, GX[me]+60*C-90, 10*C4+GY[me], 2, 0, 0, 6, 3*GSz[me]);
GY[me]+=8;
if (GY[me]>500)
{
G[me]=0;
}
}
}


/*Typ 9*/

if (GT[me]==9)
{

if (G[me]==2)
{
GH[me]=50;
GSzX[me]=30;
GSzY[me]=30;
GSz[me]=1;
GP[me]=66;
if (GY[me]>HeldY)
{
GSY[me]=-GC2[me];
}
if (GY[me]<HeldY)
{
GSY[me]=GC2[me];
}
GSX[me]=GC[me];
G[me]++;
}

if (G[me]==3)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];


if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (1390, nil);
G[me]++;
GP[me]=67;
}

if (GX[me]<=-50)
{
G[me]=0;
}
if (abs(240-GY[me])>=260)
{
G[me]=0;
}
}

if (G[me]==4)
{
createexplosion (6, GX[me]+10*C-15, GY[me], 2, 0, 0, 5, GSz[me]);
GY[me]+=8;
if (C==0)
{

}
if (GY[me]>500)
{
G[me]=0;
}
}
}

/*Boss-----------------------------------------------*/
if (GT[me]==10)
{
GSzX[me]=80;
GSzY[me]=80;

if (G[me]==2)
{
GSz[me]=0.3;
GC[me]++;
GP[me]=102;
GY[me]-=3;
GH[me]=2800;
if (GC[me]>=133)
{
GC[me]=0;
G[me]=5;
}
}

if (G[me]==5)
{
GC[me]++;
GSz[me]+=0.015;
GP[me]=101;
if(GC[me]>=47)
{
GC[me]=0;
G[me]=3;
GSz[me]=1;
}
}

if (G[me]==3)

{
if (GH[me]<-800)
{


createexplosion (1, GX[me]-150, GY[me]-10, 1, C*2-3, 20, 14, 1);
createexplosion (1, GX[me]+100, GY[me], 1, C*2-3, 20, 14, 1);

/*if (C==0)
{
createexplosion (1, GX[me]+160, GY[me]-10, 1, 0, 20, 14, 1);
createexplosion (1, GX[me]+160, GY[me]-10, 1, -4, 18, 14, 1);
createexplosion (1, GX[me]+160, GY[me]-10, 1, 4, 18, 14, 1);
}
if (C==1)
{
createexplosion (1, GX[me]-90, GY[me]-30, 1, 2, 20, 14, 1);
createexplosion (1, GX[me]-90, GY[me]-30, 1, 4, 18, 14, 1);
createexplosion (1, GX[me]-90, GY[me]-30, 1, -4, 18, 14, 1);
}
if (C==2)
{
createexplosion (1, GX[me]+160, GY[me]-30, 1, -2, 14, 14, 1);
createexplosion (1, GX[me]+160, GY[me]-30, 1, 6, 14, 14, 1);
createexplosion (1, GX[me]+160, GY[me]-30, 1, -6, 14, 14, 1);
}
if (C==3)
{
createexplosion (1, GX[me]-90, GY[me]-10, 1, -2, 14, 14, 1);
createexplosion (1, GX[me]-90, GY[me]-10, 1, -6, 14, 14, 1);
createexplosion (1, GX[me]-90, GY[me]-10, 1, 6, 14, 14, 1);
}*/
}

if (C16>0)
{
/*bu=(sqrt(((HeldX-GX[me]-265)*(HeldX-GX[me]-265))+((HeldY-GY[me])*(HeldY-GY[me]))));
bu2=(sqrt(((HeldX-GX[me]+265)*(HeldX-GX[me]+265))+((HeldY-GY[me])*(HeldY-GY[me]))));
createshot (GX[me]-265, GY[me], 8*(HeldX-GX[me]+265)/bu2, 8*(HeldY-GY[me])/bu2, 9, 3, 0);
createshot (GX[me]+265, GY[me], 8*(HeldX-GX[me]-265)/bu, 8*(HeldY-GY[me])/bu, 9, 3, 0);*/
/*searchshot (GX[me]+265, GY[me], 8, 9, 3, 0);*/
if (C0)
{
degreeshot (GX[me]-265, GY[me], 110, 35, 9, 3);
degreeshot (GX[me]+265, GY[me], 90, 35, 9, 3);
}
}

if (C16==0)
{
if (GH[me]<400)
{

}
}

GSz[me]=1;
GX[me]+=5+2*LV;
if (GH[me]<=-1000)
{
G[me]++;
damianIgnoriertFehler = AS_PlayID (1270, nil);
createexplosion (8, GX[me], GY[me], 1, 0,0, 6, 1.5);
createexplosion (8, GX[me]-100, GY[me], 1, 0,0, 6, 1.5);
createexplosion (8, GX[me]-200, GY[me], 1, 0,0, 6, 1.5);
createexplosion (8, GX[me]+100, GY[me], 1, 0,0, 6, 1.5);
createexplosion (8, GX[me]+200, GY[me], 1, 0,0, 6, 1.5);
}

if (GX[me]>550)
{
GC2[me]=1;
}
if (GX[me]<90)
{
GC2[me]=0;
}

if (GC2[me]==1)
{
GX[me]-=2*(5+2*LV);
}
if (C16==0)
{
if (C4==0)
{
createshot (GX[me]-60, GY[me]+70, 0, 12, 3, 2, 0);
createshot (GX[me]+60, GY[me]+70, 0, 12, 3, 2, 0);
}
}

if (C16==2)
{
if (C4==0)
{
damianIgnoriertFehler = AS_PlayID (29574, nil);
createshot (GX[me]-60, GY[me]+70, 0, 10+2*LV, 3, 2, 0);
createshot (GX[me]+60, GY[me]+70, 0, 10+2*LV, 3, 2, 0);
}
}

if (C4==0)
{
if (C==0)
{
if (rd>(GH[me]+2400)/40+20*LV)
{
damianIgnoriertFehler = AS_PlayID (1260, nil);
createshot (GX[me], GY[me], 0, 3, 7, 5, 0);
}
}
}
}

if (G[me]==4)
{
if (C0==0)
{
damianIgnoriertFehler = AS_PlayID (2082, nil);
}
createexplosion (1, GX[me]-GSz[me]*(rd*1.5+75), GY[me], 1, 0, GSz[me]*20, 14, GSz[me]);
createexplosion (1, GX[me]+GSz[me]*(rd3*1.5+75), GY[me], 1, 0, GSz[me]*20, 14, GSz[me]);

createexplosion (1, GX[me]+GSz[me]*(rd4*1.5-75), GY[me], 1, 0, GSz[me]*20, 14, GSz[me]);

GSz[me]-=0.005;
if (GSz[me]<=0.2)
{
G[me]=0;
P=6;
damianIgnoriertFehler = AS_PlayID (5006, nil);
createexplosion (1, GX[me], GY[me], 3, 0, 0, 15, 1);
LR();
LR();
}
}
}

/*Boss 2, Intro*/
if (GT[me]==11)
{
if (G[me]==2)
{
GH[me]=100;
GSzX[me]=50;
GSzY[me]=50;
GSz[me]=0.5;
GP[me]=114;
if (ko>GC[me])
{
GY[me]-=20;
}
if (GY[me]<-50)
{
G[me]=0;
}
}
}

/*Boss 2 Kopf*/

if (GT[me]==12)
{
GS4=GX[me];
GS5=GY[me];

if (G[me]==2)
{
GH[me]=4500;
GSzX[me]=40;
GSzY[me]=40;
GSz[me]=1;
GP[me]=111;
GY[me]+=30;
GSY[me]=0;
GSX[me]=0;
if (GY[me]>=150)
{
damianIgnoriertFehler = AS_PlayID (1006, nil);
G[me]++;
}
}

if (G[me]==3)
{

if (GH[me]>3000)
{
if (C0==0){GP[me]=111;}
if (C0==1){GP[me]=116;}

if (C==0)
{
damianIgnoriertFehler = AS_PlayID (2170, nil);

searchshot (GX[me]-20, GY[me]-20, 7+C4, 3, 6, 8);
}
}

if (GH[me]<=3000)
{
if (GH[me]>600)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(HeldX-GX[me])/bu;
GSY[me]=(HeldY-GY[me])/bu;
GS2+=9+3*LV;
GS=1;

if (abs(GY[me]-240)<240)
{
GY[me]+=GSY[me];
}
if (abs(GX[me]-310)<310)
{
GX[me]+=GSX[me];
}

if (GC3[me]==0)
{
GS3+=2;
if (GS3>350)
{
GC3[me]=1;
}
}
if (GC3[me]==1)
{
GS3-=2;
if (GS3<80)
{
GC3[me]=0;
}
}


if (C+C4==0)
{

}
}
}



if (GH[me]<=600)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSY[me]=-(HeldY-GY[me])/bu;
if (GX[me]>320)
{
GSX[me]=abs((HeldX-GX[me])/bu);
}
if (GX[me]<=320)
{
GSX[me]=-abs((HeldX-GX[me])/bu);
}

if (abs(GY[me]-240)<240)
{
GY[me]+=GSY[me];
}
if (GX[me]<580)
{
GX[me]++;
}

GS=2;


if (C4+C==0)
{
GP[me]=116;

damianIgnoriertFehler = AS_PlayID (2170, nil);

searchshot (GX[me]-20, GY[me]-20, 8, 3, 6, 2);
}
}


if (GH[me]<=0)
{
FPS=3;
G[me]++;
GP[me]=113;
GS=3;
GSX[me]=20;
GSY[me]=20;
GC[me]=0;
PicVG[2] = GetPicture(1115);
boundsVG[2] = ((**PicVG[2]).picFrame);
OboundsVG[2] = ((**PicVG[2]).picFrame);
}
}
if (G[me]==4)
{
GC[me]++;
if (GC[me]<25)
{
text (0, 1, GX[me]+GSX[me], GY[me]+GSY[me], 2);
}
if (GC[me]>180)
{
ko=0;
bgS=0;
bgC=60;
bgP=17;
damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 5, 3);
G[me]=0;
P++;

LR();
LR();
}

GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (C==0)
{
createexplosion (5, GX[me], GY[me], 1, 0, 0, 7, 2.5);
}
if (GX[me]>610)
{
GSX[me]=-20;
}
if (GY[me]>450)
{
GSY[me]=-20;
}
if (GX[me]<30)
{
GSX[me]=20;
}
if (GY[me]<30)
{
GSY[me]=20;
}
}
}

/*Boss 2 Kugel*/

if (GT[me]==13)
{

if (G[me]==2)
{
GH[me]=50000;
GSzX[me]=40;
GSzY[me]=40;
GSz[me]=1;
GP[me]=112;
GY[me]+=30;
if (GY[me]>=GC[me])
{
G[me]++;
damianIgnoriertFehler = AS_PlayID (1006, nil);
}
}

if (G[me]==3)
{
if (GS==1)
{

bu=(GS3*sin(GS2*3.14/200));
bu2=(GS3*cos(GS2*3.14/200));

if (GC2[me]==0)
{

GX[me]=GS4+bu;
GY[me]=GS5+bu2;
}
if (GC2[me]==1)
{
GX[me]=GS4-bu;
GY[me]=GS5-bu2;
}
}
if (GS==2)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(((3+2*LV)+GC2[me]*2)*(HeldX-GX[me])/bu);
GSY[me]=(((3+2*LV)+GC2[me]*2)*(HeldY-GY[me])/bu);
GX[me]+=GSX[me];
GY[me]+=GSY[me];
}
if (GS==3)
{

if (GC2[me]==0)
{
Pic[16] = GetPicture(1604);
boundsB[16] = ((**Pic[16]).picFrame);
OboundsB[16] = ((**Pic[16]).picFrame);
Pic[17] = GetPicture(1603);
boundsB[17] = ((**Pic[17]).picFrame);
OboundsB[17] = ((**Pic[17]).picFrame);
PicVG[1] = GetPicture(1114);
boundsVG[1] = ((**Sprite[112]).picFrame);
OboundsVG[1] = ((**Sprite[112]).picFrame);
createexplosion (9,GX[me], GY[me], 2, 0, 0, 9, 1);
text (0, 18, GX[me], GY[me], 1);
/*createexplosion (9,GX[me], GY[me], 1, 0, 0, 8, 1);*/
/*text (0, 9, GX[me], GY[me], 1);*/
bgS=0;
bgC=25;
bgP=16;
}
G[me]++;
GC[me]=0;
}
}

if (G[me]==4)
{
GC[me]++;
if (C0)
{
if (GC2[me]==0)
{
damianIgnoriertFehler = AS_PlayID (138, nil);
}
}
if (GC[me]>18)
{
if (GC2[me]==0)
{
damianIgnoriertFehler = AS_PlayID (5006, nil);
createexplosion (1,GX[me], GY[me], 1, 0, 0, 14, 3);
}
G[me]=0;
}
}
}

/*Schwagi Boss*/
if (GT[me]==15)
{
GSzX[me]=60;
GSzY[me]=100;

if (G[me]==2)
{
if (GC[me]==0)
{

PicVG[7] = GetPicture(128);
boundsVG[7] = ((**PicVG[7]).picFrame);
OboundsVG[7] = ((**PicVG[7]).picFrame);
text (36, 6, 320, 240, 0);
text (48, 6, 320, 240, 0);
text (60, 6, 320, 240, 0);
text (66, 40, 220, 240, 7);
play (72,18938);
play (36,18938);
play (48,18938);
play (60,18938);
damianIgnoriertFehler = AS_PlayID (21623, nil);
}
GSz[me]=0.5;
GC[me]++;
GP[me]=134;
GY[me]-=4;
GH[me]=3000;
if (GC[me]>=120)
{
damianIgnoriertFehler = AS_PlayID (11007, nil);

GC[me]=0;
G[me]=5;
}
}

if (G[me]==5)
{
GC[me]++;
GSz[me]+=0.01;
GP[me]=132;
if(GC[me]>=50)
{
GC[me]=0;
G[me]=3;
}
}

if (G[me]==3)

{
GX[me]+=(C64-1.5);
GP[me]=132;
if (GH[me]<=-500)
{
GSY[me]=0;
G[me]++;
GS=1;
PicVG[6] = GetPicture(1604);
boundsVG[6] = ((**PicVG[6]).picFrame);
OboundsVG[6] = ((**PicVG[6]).picFrame);
}

if (C16==3)
{
if (rd>50)
{
GC5[me]=0;
}
if (rd<=50)
{
GC5[me]=1;
}
}

if (C16<2)
{
if (GC5[me]==0)
{
GP[me]=131;
if (C0==0)
{
if (rd4<60+10*LV)
{
damianIgnoriertFehler = AS_PlayID (29574, nil);
degreeshot (GX[me], GY[me]+50, 100*C16+25*C4+6*C, 8, 12, 4);
}
}
}

if (GC5[me]==1)
{
if (C0==0)
{
if (rd4<100)
{
GP[me]=131;
damianIgnoriertFehler = AS_PlayID (10010, nil);
specshot (GX[me], GY[me]+50, 100*C16+25*C4+6*C, 4+LV, 1, 3,  6, 5);
}
}
}

}
}

if (G[me]==4)
{
GP[me]=135;
createexplosion (1, GX[me]-GSz[me]*(1.5*rd-75), GY[me]-GSz[me]*(1.5*rd2-75), 1, 20*GSz[me], GSz[me]*5, 7, GSz[me]);
createexplosion (1, GX[me]-GSz[me]*(1.5*rd3-75), GY[me]-GSz[me]*(1.5*rd4-75), 1, 20*GSz[me], GSz[me]*5, 7, GSz[me]);

GSz[me]-=0.005;
GY[me]+=GSY[me];
GSY[me]+=0.12;
bC+=0.02;
if (GY[me]>=600)
{
if (GC5[me]<30)
{
P=101;
}

if (GC5[me]>160)
{
Held=0;
HY[0]-=12;
HY[1]-=12;
}
	
if (GC5[me]++>200)
{
LR();
LR();
G[me]=0;
PicVG[2] = GetPicture(400);
boundsVG[2] = ((**PicVG[2]).picFrame);
OboundsVG[2] = ((**PicVG[2]).picFrame);
	
text (0, 20, 320, 240, 2);
	
L=5;
P=0;
ko=0;
p=0;
bild=0;
bild2=0;
bild3=0;
bild4=0;
bild5=0;
bild6=0;
stopsound();
}
}
}
}

/*Type 16 -  HAND*/

if (GT[me]==16)
{
GSzX[me]=50;
GSzY[me]=70;

if (G[me]==2)
{
GS=0;
GSz[me]=0.75;
GP[me]=136;
GY[me]+=2;
GH[me]=2000;
if (180<=GY[me])
{
GC[me]=0;
G[me]=3;
}
}

if (G[me]==3)
{
GP[me]=136;

if (GS==1)
{
G[me]++;
}
if (C==0)
{
if (GC4[me]==0)
{
if (rd>94)
{
damianIgnoriertFehler = AS_PlayID (2050, nil);
degree (me, GX[me], GY[me]);

GSX[me]=(11+4*LV)*cos(GC5[me]*3.14/200);
GSY[me]=(11+4*LV)*sin(GC5[me]*3.14/200);
GC4[me]=1;
}
}
}

if (GC4[me]==1)
{
GP[me]=137;
GX[me]+=GSX[me];
GY[me]+=GSY[me];
GC3[me]++;
if (GC3[me]>40)
{
GC4[me]=2;
}
}

if (GC4[me]==2)
{
GP[me]=137;
GX[me]-=GSX[me];
GY[me]-=GSY[me];
GC3[me]--;
if (GC3[me]<=0)
{
GC4[me]=0;
}
}
}

if (G[me]==4)
{
GP[me]=137;
createexplosion (7, GX[me]-GSz[me]*(1.5*rd-75), GY[me]-GSz[me]*(1.5*rd2-75), 2, 0, GSz[me]*5, 7, GSz[me]);

GSz[me]-=0.002;
if (GSz[me]<=0.53)
{
G[me]=0;
createexplosion (7, GX[me]-32, GY[me]-32, 3, 8, 8, 6, 1.5);
createexplosion (7, GX[me]-48, GY[me], 3, 12, 0, 6, 1.5);
createexplosion (7, GX[me]-32, GY[me]+32, 3, 8, -8, 6, 1.5);
createexplosion (7, GX[me]+32, GY[me]-32, 3, -8, 8, 6, 1.5);
createexplosion (7, GX[me]+32, GY[me]+32, 3, -8, -8, 6, 1.5);

createexplosion (7, GX[me], GY[me]-48, 3, 0, 12, 6, 1.5);
createexplosion (7, GX[me]+48, GY[me], 3, -12, 0, 6, 1.5);
createexplosion (7, GX[me], GY[me]+48, 3, 0, -12, 6, 1.5);
/*createexplosion (7, GX[me], GY[me], 3, 0, 0, 6, 1.5);*/

}
}
}

/*Type 17 -  AHA Synthesizer*/

if (GT[me]==17)
{
GSzX[me]=65;
GSzY[me]=60;

if (G[me]==2)
{
if (GC[me]==0)
{
PicVG[7] = GetPicture(129);
boundsVG[7] = ((**PicVG[7]).picFrame);
OboundsVG[7] = ((**PicVG[7]).picFrame);
text (0, 6, 320, 240, 0);
text (12, 6, 320, 240, 0);
text (24, 6, 320, 240, 0);
text (36, 6, 320, 240, 0);
text (48, 6, 320, 240, 0);
text (55, 40, 220, 320, 7);
}
GC[me]++;
GSz[me]=1;
GP[me]=122;
GY[me]+=bC*20;
GH[me]=3000;
GC2[me]=GX[me];
if (100<=GY[me])
{
GC[me]=0;
G[me]=3;
bC=0;
}
}

if (G[me]==3)
{


GX[me]+=((3000-GH[me])/600)*((3000-GH[me])/600);
GC2[me]+=((3000-GH[me])/600)*((3000-GH[me])/600);

if (GH[me]>2000)
{
if (C0)
{
damianIgnoriertFehler = AS_PlayID (23061, nil);
degreeshot (GX[me]-10, GY[me]-10, 100+(1-0.25*LV)*(-150+rd+2*rd2), 8, 3, 0);
}
}

if (GH[me]<=2000)
{
if (C4==0)
{
degree (me, GX[me]-10, GY[me]-10);
}
if (C4>1-LV)
{
if (C0)
{
damianIgnoriertFehler = AS_PlayID (23061, nil);
degreeshot (GX[me]-10, GY[me]-10, GC5[me], 8, 3, 6*(C/2));
}
if (rd4<5+LV)
{
createenemy (GX[me]-10, GY[me]-10, 22, 0, rd+rd2+rd3+rd4, 7, 5, 100);
}
}
}

if (GC2[me]>=490)
{GC[me]=1;}

if (GC2[me]<=150)
{GC[me]=0;}

if (GC[me]==1)
{
GX[me]-=2*((3000-GH[me])/600)*((3000-GH[me])/600);
GC2[me]-=2*((3000-GH[me])/600)*((3000-GH[me])/600);
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (1270, nil);
G[me]++;
GS=1;
GSX[me]=0.03;
createexplosion (8, GX[me], GY[me], 1, 0, 0, 6, 1.5);
}
}

if (G[me]==4)
{
GY[me]-=GSz[me];
GSz[me]+=GSX[me]*GSz[me];
GSX[me]-=0.0015;
if (GSz[me]<0.2)
{
damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 3, 0, 0, 6, 0.5);
LR();
G[me]=0;
}
}
}

/*TYP 20 - AHA HELP*/

if (GT[me]==20)
{
if (G[me]==2)
{
GSz[me]=0.99;
GP[me]=121;
FPS=3;
if (GY[me]<=100)
{
GY[me]+=bC*20;
}
if (GS==1)
{
G[me]=4;
}
}
if (G[me]==4)
{
GY[me]+=bC*20;
bC+=0.01;
if (bC>=0.15)
{
if (C0)
{
damianIgnoriertFehler = AS_PlayID (1270, nil);
}
createexplosion (8, GX[me]-200+4*rd, GY[me]-100+2*rd2, 2, 0, 0, 5, 1);
createexplosion (5, GX[me]-200+4*rd3, GY[me]-100+2*rd4, 2, 0, 0, 5, 1);
}
if (GY[me]>=700)
{
G[me]=0;
GS=1;

createexplosion (5, GX[me], GY[me], 3, 0, -20, 5, 2);
createexplosion (5, GX[me]+5, GY[me], 3, 4, -18, 5, 2);
createexplosion (5, GX[me]-5, GY[me], 3, -4, -18, 5, 2);
createexplosion (5, GX[me]+10, GY[me], 3, 8, -15, 5, 2);
createexplosion (5, GX[me]-10, GY[me], 3, -8, -15, 5, 2);
stopsound();
DaLoadFile (123);

	
ee(320, 610, 15, ko+100);
ee(150, -100, 16, ko+360);   /*BOSS SCHWAGI*/
ee(490, -100, 16, ko+360);
P=10;
}
}
}

/* Type 21*/

if (GT[me]==21)
{

if (G[me]==2)
{
GH[me]=20;
G[me]=3;
GSzX[me]=60;
GSzY[me]=10;
GSz[me]=1;
GSX[me]=GC[me];
GSY[me]=GC2[me];
GP[me]=81;
}


if (G[me]==3) 
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];
if (GH[me]<=0)
{
G[me]++;
}
if (abs(GX[me]-400)>=600)
{
G[me]++;
}
}

if (G[me]==4)
{
GY[me]-=GSY[me];
GX[me]+=GSX[me];

GSX[me]-=1;
GSY[me]-=0.15;
if (C==0)
{
createexplosion (5, GX[me]+(rd2-50), GY[me]+((rd-50)/3), 1, -18, -3, 8, 1);
GC3[me]++;
if (GC3[me]>=10)
{
damianIgnoriertFehler = AS_PlayID (10000, nil);
createexplosion (8, GX[me]+25, GY[me], 2, 0, 0, 6, 1);
createexplosion (8, GX[me]-25, GY[me], 2, 0, 0, 6, 1);
G[me]=0;
}
}
}

}

/*Type 22 - Rocket*/

if (GT[me]==22)
{

if (G[me]==2)
{
GH[me]=40;
G[me]=3;
GSzX[me]=5;
GSzY[me]=5;
GSz[me]=1;
}


if (G[me]==3) 
{


/*bu2=sqrt(  abs(HeldX-GX[me]) / ( (HeldX-GX[me])*(HeldX-GX[me])+(HeldY-GY[me])*(HeldY-GY[me]) ) );/*sin*/
/*bu=sqrt( abs(HeldY-GY[me]) / ( (HeldX-GX[me])*(HeldX-GX[me])+(HeldY-GY[me])*(HeldY-GY[me]) ) );/*cos*/


/*if (bu>=0)
{
if (bu2>=0)
{
bu3=asin(bu2)*200/3.14;
}
if (bu2<0)
{
bu3=200+(asin(bu2)*200/3.14);
}
}

if (bu<0)
{
if (bu2>=0)
{
bu3=400+(asin(bu2)*200/3.14);
}
if (bu2<=0)
{
bu3=200-(asin(bu2)*200/3.14);
}
}*/

degree (me, GX[me], GY[me]);

if (abs(GC[me]-GC5[me]<200))
{
if (GC[me]>GC5[me])
{
GC[me]-=GC3[me];
}

if (GC[me]<=GC5[me])
{
GC[me]+=GC3[me];
}
}

if (abs(GC[me]-GC5[me]>200))
{
if (GC[me]>GC5[me])
{
GC[me]+=GC3[me];
}

if (GC[me]<=GC5[me])
{
GC[me]-=GC3[me];
}
}


if (GC[me]>400)
{
GC[me]-=400;
}

if (GC[me]<0)
{
GC[me]+=400;
}



GSY[me]=GC2[me]*sin(GC[me]*3.14/200);
GSX[me]=GC2[me]*cos(GC[me]*3.14/200);

GY[me]+=GSY[me];
GX[me]+=GSX[me];


if (GC[me]<12.5)
{
GP[me]=123;
}


if (GC[me]>=12.5)
{
if (GC[me]<37.5)
{
GP[me]=124;
}
}

if (GC[me]>=37.5)
{
if (GC[me]<62.5)
{
GP[me]=125;
}
}

if (GC[me]>=62.5)
{
if (GC[me]<87.5)
{
GP[me]=126;
}
}

if (GC[me]>=87.5)
{
if (GC[me]<112.5)
{
GP[me]=127;
}
}

if (GC[me]>=112.5)
{
if (GC[me]<137.5)
{
GP[me]=128;
}
}

if (GC[me]>=137.5)
{
if (GC[me]<162.5)
{
GP[me]=129;
}
}

if (GC[me]>=162.5)
{
if (GC[me]<187.5)
{
GP[me]=130;
}
}

if (GC[me]>=187.5)
{
if (GC[me]<212.5)
{
GP[me]=140;
}
}

if (GC[me]>=212.5)
{
if (GC[me]<237.5)
{
GP[me]=141;
}
}

if (GC[me]>=237.5)
{
if (GC[me]<262.5)
{
GP[me]=142;
}
}

if (GC[me]>=262.5)
{
if (GC[me]<287.5)
{
GP[me]=143;
}
}

if (GC[me]>=287.5)
{
if (GC[me]<312.5)
{
GP[me]=144;
}
}

if (GC[me]>=312.5)
{
if (GC[me]<337.5)
{
GP[me]=145;
}
}

if (GC[me]>=337.5)
{
if (GC[me]<362.5)
{
GP[me]=146;
}
}

if (GC[me]>=362.5)
{
if (GC[me]<387.5)
{
GP[me]=147;
}
}

if (GC[me]>=387.5)
{
GP[me]=123;
}


if (GH[me]<=0)
{
G[me]++;
}

if (GC4[me]--<=0)
{
G[me]++;
}

}

if (G[me]==4)
{
damianIgnoriertFehler = AS_PlayID (2081, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 1);
G[me]=0;
}

if (G[me]!=3)
{
G[me]=0;
}

}

/*Type 23 Drone Gross*/

if (GT[me]==23)
{

if (G[me]==2)
{
GH[me]=700;
G[me]=3;
GSzX[me]=80;
GSzY[me]=80;
GSz[me]=1;
GSX[me]=GC[me];
GSY[me]=GC2[me];
GP[me]=71;
}


if (G[me]==3) 
{
if (GX[me]>400)
{
GY[me]+=GSY[me];
GX[me]+=GSX[me];
}

if (GH[me]<=0)
{
G[me]++;
GC3[me]=0;
}

if (C4+C==0)
{
createenemy (GX[me]-25, GY[me]+10, 22, 0, 10+(2*rd), 10, rd2/10, 100); 
}

}

if (G[me]==4)
{
GY[me]+=3;
GP[me]=72;
if (C0)
{
createexplosion (5, GX[me]+(rd2-50), GY[me]+((rd-50)/3), 1, -18, -3, 8, 3);
GC3[me]++;
if (GY[me]>=600)
{
createexplosion (9, 320, 240, 1, 0, 0, 1, 1);
damianIgnoriertFehler = AS_PlayID (10011, nil);
G[me]=0;
}
}
}

}


/*Type 24 Komischer Vogel*/

if (GT[me]==24)
{

if (G[me]==1)
{
GSzX[me]=50;
GSzY[me]=45;
GP[me]=96;
GSz[me]=0.05;
}

if (G[me]==2)
{
GSz[me]=GSz[me]*1.03;
GY[me]+=GSz[me]*(GY[me]-240)/40;
GY[me]-=GSz[me];
GX[me]+=GSz[me]*(GX[me]-320)/40;
GH[me]=100;
if (GSz[me]>=0.98)
{
damianIgnoriertFehler = AS_PlayID (10026, nil);
GSz[me]=1;
G[me]=3;
}
}

if (G[me]==3)
{
GP[me]=96;
GY[me]-=1;

if (GY[me]<-100)
{
G[me]=0;
}

if (C4==0)
{
if (C==0)
{
damianIgnoriertFehler = AS_PlayID (10018, nil);
}
GP[me]=97;
if (C>1-2*LV)
{
searchshot (GX[me], GY[me]+18, 10, 3, 6, 0);
}
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (10013, nil);
damianIgnoriertFehler = AS_PlayID (1270, nil);
createexplosion (8, GX[me], GY[me], 1, 0, 0, 6, 1.5);
G[me]=4;
}
}

if (G[me]==4)
{
GY[me]+=1.5;
GSz[me]-=0.03*GSz[me];

GY[me]-=GSz[me]*(GY[me]-240)/40;
GX[me]-=GSz[me]*(GX[me]-320)/40;

GY[me]+=GSz[me];
if (C0)
{
createexplosion (5, GX[me], GY[me], 1, 15*sqrt(GSz[me])*sin(rd4*3.14/100), 15*sqrt(GSz[me])*cos(rd4*3.14/100)+20, 6, 1.5*GSz[me]);
}
if (GSz[me]<0.05)
{
G[me]=0;
}
}

}


/*Type 25 (Hilfsplattform)*/

if (GT[me]==25)
{

if (G[me]==1)
{
GSz[me]=0.65;
GP[me]=148;
GC[me]=0;
}

if (G[me]==2)
{

if (GC[me]<=1)
{
if (GSY[me]<0)
{
GY[me]+=GSY[me];
}
}

if (GC[me]>20)
{
GY[me]+=GSY[me];
}


if (GC[me]<20)
{
if (GC[me]>0)
{
bC7=-13*bC;
}
}

GSY[me]=13*bC+bC7;
GS5=GY[me];

if (GC[me]<=0)
{
if (13*bC+bC7>-5)
{
bC7-=1;
}
}

if (GY[me]<=100)
{
GC[me]++;
}

if (GC[me]>=20)
{
bC7+=0.5;
if (GY[me]>=600)
{
GS5=0;
G[me]=0;
bC7=0;
}
}
}

}


/*Type 26 Komisches Photoshopabfalldingsbunms*/

if (GT[me]==26)
{

if (G[me]==1)
{
GSzX[me]=70;
GSzY[me]=60;
GP[me]=103;
GSz[me]=0.6;
}

if (G[me]==2)
{

GP[me]=104;

if (GC[me]==0)
{
GY[me]=GS5;
}

if (GS5<=100)
{
if (GS5>=10)
{
GC[me]=1;
}
}

if (GC[me]==1)
{
GSz[me]+=0.002;
GH[me]=350+50*LV;
if (GSz[me]>=1)
{
GSz[me]=1;
G[me]=3;
}
}
}

if (G[me]==3)
{
GP[me]=104;
GX[me]+=(C4-1.5)*2;

if (C4==0)
{
degreeshot (GX[me], GY[me], 40*(C+2)-20, 7, 4, 9);
}

if (GH[me]<=0)
{
G[me]++;

}
}

if (G[me]==4)
{
GY[me]+=10*GSz[me];
GSz[me]=1.1*GSz[me];

if (C0)
{
damianIgnoriertFehler = AS_PlayID (1270, nil);
createexplosion (8, GX[me], GY[me], 1, 0, 0, 6, 1.5*GSz[me]);
}
if (GY[me]>800)
{
G[me]=0;
}
}

}



/*Regen (Type 27)*/

if (GT[me]==27)
{
if (G[me]==2)
{
GSz[me]=2;

GX[me]+=4*(C4-1.5);

if (C==0)
{
GP[me]=149;
}

if (C==1)
{
GP[me]=30;
}

if (C==2)
{
GP[me]=149;
}

if (C==3)
{
GP[me]=29;
}


if (GS==27)
{
G[me]=0;
}

}

}


/*Regen (Type 28)*/

if (GT[me]==28)
{
if (G[me]==2)
{
GSz[me]=2;

GX[me]-=4*(C4-1.5);

if (C==0)
{
GP[me]=29;
}

if (C==1)
{
GP[me]=149;
}

if (C==2)
{
GP[me]=30;
}

if (C==3)
{
GP[me]=149;
}


if (GS==27)
{
G[me]=0;
}

}

}


/*Type 29 S.K.*/

if (GT[me]==29)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=150;
GSzY[me]=60;
GSX[me]=GC[me];
GSY[me]=GC2[me];
GP[me]=32;
GH[me]=300;
G[me]++;
}

if (G[me]==3)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (C==0)
{
if (rd2<50)
{
degreeshot (GX[me]-125, GY[me]+65, 100+(GC3[me]*(rd-50)/10), 10, 4, 1);
}
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (1260, nil);
damianIgnoriertFehler = AS_PlayID (1270, nil);


createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2);

createexplosion (6, GX[me], GY[me], 4, 0, 10, 6, 2);
createexplosion (6, GX[me], GY[me], 4, 0, -10, 6, 2);
createexplosion (6, GX[me], GY[me], 4, 10, 0, 6, 2);
createexplosion (6, GX[me], GY[me], 4, -10, 0, 6, 2);
createexplosion (6, GX[me], GY[me], 4, 7, 7, 6, 2);
createexplosion (6, GX[me], GY[me], 4, -7, -7, 6, 2);
createexplosion (6, GX[me], GY[me], 4, -7, 7, 6, 2);
createexplosion (6, GX[me], GY[me], 4, 7, -7, 6, 2);

G[me]=0;
}

if (abs(GX[me]-320)>=480)
{
G[me]=0;
}

if (abs(GY[me]-240)>=400)
{
G[me]=0;
}


}

}


/*Type 30 (Blauer Zahnarzt)*/

if (GT[me]==30)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=30;
GSzY[me]=40;
GSX[me]=GC[me];
GSY[me]=GC2[me];
GP[me]=41;
GH[me]=60;
G[me]++;
}

if (G[me]==3)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

GSz[me]+=(C4-1.5)*0.01;
GP[me]=41;

if (C==0)
{
if (rd2<19+7*LV)
{
GP[me]=42;
damianIgnoriertFehler = AS_PlayID (10447, nil);
searchshot (GX[me], GY[me], 8+2*LV, 4, 9, 0);
}
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (1390, nil);
G[me]=4;
}

if (abs(GX[me]-320)>=480)
{
G[me]=0;
}

if (abs(GY[me]-240)>=400)
{
G[me]=0;
}

}

if (G[me]==4)

{
GSz[me]-=0.02;
createexplosion (7, GX[me]+((rd3-50)/3), GY[me]+((rd4-50)/2), 1, 0, 0, 9, GSz[me]);
GY[me]+=4*GSz[me];

if (bC1==0)
{
if (GSz[me]<0.2)
{
damianIgnoriertFehler = AS_PlayID (25339, nil);

createexplosion (0, GX[me], GY[me], 2, 0, 0, 9, 0.3);
G[me]=0;
}
}

if (bC1>0)
{
if (GSz[me]<0.5)
{
damianIgnoriertFehler = AS_PlayID (25339, nil);

createexplosion (0, GX[me], GY[me], 2, 0, 0, 9, 0.8);
G[me]=0;
}
}


}

}


/*Type 31, **/

if (GT[me]==31)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=70;
GSzY[me]=70;
GP[me]=31;
GH[me]=200;
G[me]++;
damianIgnoriertFehler = AS_PlayID (10026, nil);

}

if (G[me]==3)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(5+LV)*(HeldX-GX[me])/bu;
GSY[me]=(5+LV)*(HeldY-GY[me])/bu;

GX[me]+=GSX[me];
GY[me]+=GSY[me];



if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (1270, nil);


createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 1.5);

createexplosion (6, GX[me], GY[me], 4, 0, 10, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, 0, -10, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, 10, 0, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, -10, 0, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, 7, 7, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, -7, -7, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, -7, 7, 6, 1.5);
createexplosion (6, GX[me], GY[me], 4, 7, -7, 6, 1.5);

G[me]=0;
}


}

}

/*Type 32, Spht*/

if (GT[me]==32)
{
if (G[me]==2)
{
GP[me]=0;
GC[me]-=6;
GC2[me]+=40;

createexplosion (6, GX[me]+GC[me]*sin(GC2[me]*3.14/400), GY[me]-GC[me]*cos(GC2[me]*3.14/400), 1, 0, 0, 6, 1);
createexplosion (6, GX[me]-GC[me]*sin(GC2[me]*3.14/400), GY[me]+GC[me]*cos(GC2[me]*3.14/400), 1, 0, 0, 6, 1);

if (GC[me]<=5)
{
createexplosion (6, GX[me], GY[me], 2, 0, 5, 6, 2);
createexplosion (6, GX[me], GY[me], 2, 5, 0, 6, 2);
createexplosion (6, GX[me], GY[me], 2, 0, -5, 6, 2);
createexplosion (6, GX[me], GY[me], 2, -5, 0, 6, 2);
createexplosion (6, GX[me], GY[me], 2, 3, 3, 6, 2);
createexplosion (6, GX[me], GY[me], 2, 3, -3, 6, 2);
createexplosion (6, GX[me], GY[me], 2, -3, 3, 6, 2);
createexplosion (6, GX[me], GY[me], 2, -3, -3, 6, 2);
createexplosion (6, GX[me], GY[me], 2, 0, 0, 6, 3);
GSz[me]=1;
GSzX[me]=40;
GSzY[me]=90;
GP[me]=78;
GH[me]=150;
G[me]++;
damianIgnoriertFehler = AS_PlayID (1390, nil);
}
}

if (G[me]==3)
{
GX[me]-=GSX[me];
GY[me]-=GSY[me];

bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=2*(HeldX-GX[me])/bu;
GSY[me]=2*(HeldY-GY[me])/bu;

if (C16==0)
{
degree (me, GX[me], GY[me]);
}

GP[me]=76;

if (C4<=1)
{
GP[me]=77;
if (rd2<35+5*LV)
{
degreeshot (GX[me], GY[me]-20, GC5[me]+(GC3[me]*(rd-50)/10), 8+2*LV, 4, 9);
}
}

if (GH[me]<=0)
{
damianIgnoriertFehler = AS_PlayID (138, nil);

bgS=0;
bgC=2;
bgP=19;
createexplosion (7, GX[me]-32, GY[me]-32, 3, 8, 8, 6, 1.5);
createexplosion (7, GX[me]-48, GY[me], 3, 12, 0, 6, 1.5);
createexplosion (7, GX[me]-32, GY[me]+32, 3, 8, -8, 6, 1.5);
createexplosion (7, GX[me]+32, GY[me]-32, 3, -8, 8, 6, 1.5);
createexplosion (7, GX[me]+32, GY[me]+32, 3, -8, -8, 6, 1.5);
createexplosion (7, GX[me], GY[me]-48, 3, 0, 12, 6, 1.5);
createexplosion (7, GX[me]+48, GY[me], 3, -12, 0, 6, 1.5);
createexplosion (7, GX[me], GY[me]+48, 3, 0, -12, 6, 1.5);

G[me]=4;
GC[me]=14;
GP[me]=78;
}

if (abs(GX[me]-320)>=480)
{
G[me]=0;
}

if (abs(GY[me]-240)>=400)
{
G[me]=0;
}

}

if (G[me]==4)
{
if (GC[me]--<=0)
{
G[me]=0;
}
}

}


/*Type 33, MUSHA*/

if (GT[me]==33)
{

if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=90;
GSzY[me]=40;
GP[me]=78;
GH[me]=200;
G[me]++;
GP[me]=61;
}

if (G[me]==3)
{

if (GC[me]==0)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

GSY[me]=C4-1.5;

if (HeldX>GX[me])
{
GSX[me]=4;
}
if (HeldX<GX[me])
{
GSX[me]=-4;
}
}

if (abs(HeldX-GX[me])<50)
{
GC[me]=1;
GC2[me]=16;
}

if (GC[me]==1)
{
GC2[me]--;

if (C4<=1+2*LV)
{
if (C<=1)
{
if (C0)
{
GP[me]=61;
damianIgnoriertFehler = AS_PlayID (1330, nil);

createshot (GX[me]-48, GY[me]+22, 0, 10, 3, 0, 0);
}
}
}

if (C4<=1+2*LV)
{
if (C>=2)
{
if (C0)
{
GP[me]=62;
damianIgnoriertFehler = AS_PlayID (1330, nil);

createshot(GX[me]+48, GY[me]+22, 0, 10, 3, 0, 0);
}
}
}

if (GC2[me]<=0)
{
GC[me]=0;
}
}


if (GH[me]<=0)
{
G[me]=4;
GC[me]=20;
}

if (abs(GX[me]-320)>=480)
{
G[me]=0;
}

if (abs(GY[me]-240)>=400)
{
G[me]=0;
}
}


if (G[me]==4)
{
if (C0==0)
{
GP[me]=63;
}

if (C0==1)
{
GP[me]=64;
}

if (GC[me]--<=0)
{
G[me]=0;
damianIgnoriertFehler = AS_PlayID (1270, nil);

createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 1.5);
}
}

}


/*Type 34, Smartbomb*/

if (GT[me]==34)
{

if (G[me]==2)
{
heldhit (0, 100, 0);
heldhit (1, 100, 0);
timev[0]=100;
timev[1]=100;
GSz[me]=1;
GSzX[me]=-100;
GSzY[me]=-100;
GP[me]=43;
GH[me]=200;
G[me]++;
GC[me]=0;

text (0, 31, 500, 360, 8);
text (31, 10, 500, 360, 9);
text (40, 25, 500, 360, 10);

}

if (G[me]==3)
{


GY[me]-=10;
GC[me]++;
if (GC[me]>=32)
{
for (bu4=0; bu4<128; bu4++)
{
if (G[bu4]==3)
{
GH[bu4]-=500;
}
}


damianIgnoriertFehler = AS_PlayID (128, nil);

createexplosion (8, 120, 120, 2, -5, -5, 6, 1);
createexplosion (8, 200, 120, 2, -3, -7, 6, 1);
createexplosion (8, 280, 120, 2, -1, -10, 6, 1);
createexplosion (8, 360, 120, 2, 1, -10, 6, 1);
createexplosion (8, 440, 120, 2, 3, -7, 6, 1);
createexplosion (8, 520, 120, 2, 5, -5, 6, 1);
createexplosion (8, 120, 200, 2, -7, -3, 6, 1);
createexplosion (8, 200, 200, 2, -5, -5, 6, 1);
createexplosion (8, 280, 200, 2, -3, -7, 6, 1);
createexplosion (8, 360, 200, 2, 3, -7, 6, 1);
createexplosion (8, 440, 200, 2, 5, -5, 6, 1);
createexplosion (8, 520, 200, 2, 7, -3, 6, 1);

createexplosion (8, 120, 280, 2, -7, 3, 6, 1);
createexplosion (8, 200, 280, 2, -5, 5, 6, 1);
createexplosion (8, 280, 280, 2, -3, 7, 6, 1);
createexplosion (8, 360, 280, 2, 3, 7, 6, 1);
createexplosion (8, 440, 280, 2, 5, 5, 6, 1);
createexplosion (8, 520, 280, 2, 7, 3, 6, 1);
createexplosion (8, 120, 360, 2, -5, 5, 6, 1);
createexplosion (8, 200, 360, 2, -3, 7, 6, 1);
createexplosion (8, 280, 360, 2, -1, 10, 6, 1);
createexplosion (8, 360, 360, 2, 1, 10, 6, 1);
createexplosion (8, 440, 360, 2, 3, 7, 6, 1);
createexplosion (8, 520, 360, 2, 5, 5, 6, 1);

G[me]=0;
}

}

}

/*Type 35 Power Bomb*/

if (GT[me]==35)
{

if (G[me]==2)
{
damianIgnoriertFehler = AS_PlayID (1290, nil);
GSz[me]=1;
GSzX[me]=-100;
GSzY[me]=-100;
GP[me]=144;
GH[me]=200;
G[me]++;
GC[me]=0;
}

if (G[me]==3)
{


GY[me]-=10;
GC[me]++;
if (GC[me]>=15)
{
for (bu4=0; bu4<128; bu4++)
{
if (G[bu4]==3)
{
if (abs(GX[me]-GX[bu4])<150)
{
if (abs(GY[me]-GY[bu4])<150)
{
GH[bu4]-=250;
}
}
}
}

for (bu4=1; bu4<100; bu4++)
{
if (abs(GX[me]-SX[bu4])<150)
{
if (abs(GY[me]-SY[bu4])<150)
{
S[bu4]=0;
}
}
}
damianIgnoriertFehler = AS_PlayID (1270, nil);
createexplosion (8, GX[me], GY[me], 3, 0, 0, 6, 2);
G[me]=0;
}

}

}

/*Type 36, Flamme bei PB*/

if (GT[me]==36)
{
GX[me]=HX[0];
GY[me]=HY[0]-40;
GSz[me]=0.5;

GP[me]=57+C4;
if (PB<60) 
{
 GP[me]=149;
}

if (Held<=0)
GP[me]=149;

if (LT==1)
GP[me]=149;

}

/*Type 37, Flamme bei PB (2)*/

if (GT[me]==37)
{
GP[me]=149;
if (P2)
{
GX[me]=HX[1];
GY[me]=HY[1]-40;
GSz[me]=0.5;

GP[me]=57+C4;
if (PB<60)
{
GP[me]=49;
}

if (Held<=0)
GP[me]=149;

if (LT==1)
GP[me]=149;
}
}


/*Type 38 Babuschka*/

if (GT[me]==38)
{
if (G[me]==2)
{
GSz[me]=1.5;
GSzX[me]=70;
GSzY[me]=130;
GH[me]=3800;
GP[me]=86;
GY[me]+=2;
bC2=10;
GC3[me]=0;

if (GY[me]>100)
{
G[me]++;
}
}

if (G[me]==3)
{

if (GC3[me]++>30)
{
if (GC[me]==0)
{
GX[me]+=6-4*C16;
GY[me]+=1.5-C4;
GP[me]=86;

if (C4+C==0)
{
if (rd<70)
{
GP[me]=87;
createenemy (GX[me], GY[me]+110, 41, 0, 0, 20, 28, 0);
}
}  

if (GH[me]<2500)
{
ee (0, 0, 49, 0);
 	ee (0, 0, 49, 0);
GS6=GSz[me];
createenemy (GX[me], GY[me]-50, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+50, 40, 0, 0, 0, 0, 0);
GSzX[me]=46;
GSzY[me]=86;
GC[me]++;
GSz[me]=1;
/*LR();*/
GSY[me]=10;
bC2=20;
GC3[me]=0;
damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2*GSz[me]);
}
}

if (GC3[me]>30)
{
if (GC[me]==1)
{

GP[me]=87;

if (C0)
{
GP[me]=86;
}

bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]+=(HeldX-GX[me])/bu;
GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (abs(GX[me]-320)>320)
{
GSX[me]=GSX[me]*(-1);
GX[me]+=GSX[me];
GX[me]+=GSX[me];
}

if (abs(GY[me]-240)>240)
{
GSY[me]=GSY[me]*(-1);
GY[me]+=GSY[me];
GY[me]+=GSY[me];
}

if (GH[me]<1500)
{
ee (0, 0, 49, 0);
ee (0, 0, 49, 0);
GS6=GSz[me];
createenemy (GX[me], GY[me]-50, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+50, 40, 0, 0, 0, 0, 0);
GC[me]++;
GSz[me]=0.75;
GSzX[me]=31;
GSzY[me]=59;
LR();
bC2=50;
GC3[me]=0;
bC=2;

damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2*GSz[me]);
}
}
}


if (GC3[me]>30)
{
if (GC[me]==2)
{
GP[me]=86;

if (GH[me]<0)
{
ee (0, 0, 49, 0);
ee (0, 0, 49, 0);
GS6=GSz[me];
createenemy (GX[me], GY[me]-50, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+50, 40, 0, 0, 0, 0, 0);
GC[me]++;
GSz[me]=0.5;
GSzX[me]=20;
GSzY[me]=40;
/*LR();*/
bC2=100;
GC3[me]=0;
bC=4;

damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2*GSz[me]);
}


if (abs(GX[me])<300)
{
GX[me]+=5;
}

if (abs(GX[me])>340)
{
GX[me]-=5;
}

if (abs(GY[me])<100)
{
GY[me]+=5;
}

if (abs(GY[me])>140)
{
GY[me]-=5;
}

if (C==0)
{
GP[me]=87;
}
if (C+C4==0)
{
if (C16==0)
{
degreeshot (GX[me], GY[me]+60, 100, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 70, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 130, 8, 5, 7);
}

if (C16==1)
{
degreeshot (GX[me], GY[me]+60, 115, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 85, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 145, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 40, 8, 5, 7);
}

if (C16==2)
{
degreeshot (GX[me], GY[me]+60, 100, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 70, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 130, 8, 5, 7);
}

if (C16==3)
{
degreeshot (GX[me], GY[me]+60, 115, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 85, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 145, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 40, 8, 5, 7);
}

}


if (C==0)
{
if (C4==2)
{
if (C16==0)
{
searchshot (GX[me], GY[me]+60, 7, 5, 7, 0);
}

if (LV)
{
if (C16==1)
{
degreeshot (GX[me], GY[me]+60, 0, 8, 5, 7);
degreeshot (GX[me], GY[me]+60, 200, 8, 5, 7);
}

if (C16==2)
{
searchshot (GX[me], GY[me]+60, 7, 5, 7, 0);
}

if (C16==3)
{
if (LV)
{
degreeshot (GX[me], GY[me]+60, 100, 8, 5, 7);
}
}
}
}
}
}
}



if (GC3[me]>30)
{
if (GC[me]==3)
{




GX[me]+=GSX[me];
GY[me]+=GSY[me];
GC4[me]--;
if (sqrt(GSX[me]*GSX[me]+GSY[me]*GSY[me])<34+6*LV-(GH[me]/100))
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]+=(0.4+0.3*LV)*(HeldX-GX[me])/bu;
GSY[me]+=(0.4+0.3*LV)*(HeldY-GY[me])/bu;
}

if (sqrt(GSX[me]*GSX[me]+GSY[me]*GSY[me])>=34+6*LV-(GH[me]/100))
{
GSX[me]=0;
GSY[me]=0;
}

if (GC4[me]<0)
{
if (abs(GX[me]-320)>320)
{
GC4[me]=10;
GSX[me]=GSX[me]*(-0.5);
GSY[me]=GSY[me]*(0.5);
}

if (abs(GY[me]-240)>240)
{
GC4[me]=10;
GSY[me]=GSY[me]*(-0.5);
GSX[me]=GSX[me]*(0.5);
}
}




GP[me]=86;

if (C==0)
{
if (rd*2<(800-GH[me])/25+10*LV)
{
searchshot (GX[me], GY[me]+60, 7, 2, 6, 0);
}
}

if (GH[me]<-1200)
{
ee (0, 0, 49, 0);
ee (0, 0, 49, 0);
GS6=GSz[me];
createenemy (GX[me], GY[me]-30, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+30, 40, 0, 0, 0, 0, 0);
GC[me]=10;
GSz[me]=0.25;
GSzX[me]=25;
GSzY[me]=25;
LR();
bC2=250;
GC3[me]=0;
bC=10;

GC2[me]=0;
GC4[me]=0;
GC5[me]=0;
damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2*GSz[me]);
p=0;
}


if (C>1)
{
GP[me]=91;
}
}
}


if (GC3[me]>30)
{
if (GC[me]==4)
{





GC4[me]+=((-GH[me]-700)/35-5*LV);

GX[me]=320+250*sin(GC4[me]*3.14/400);
GY[me]=240+190*cos(GC4[me]*3.14/400);

if (GH[me]<-1800)
{
GS6=GSz[me];
createenemy (GX[me], GY[me]-20, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+20, 40, 0, 0, 0, 0, 0);
GC[me]++;
GSz[me]=0.1;
GSzX[me]=10;
GSzY[me]=20;
LR();
bC2=1000;
GC3[me]=0;
bC=40;

damianIgnoriertFehler = AS_PlayID (1272, nil);
createexplosion (8, GX[me], GY[me], 2, 0, 0, 6, 2*GSz[me]);
p=0;
}


if (C==0)
{
if (3*rd-2*LV<((-GH[me]-700)/12))
{
searchshot (GX[me], GY[me], 7+LV, 2, 6, 0);
}
}
}
}

if (GC3[me]>30)
{
if (GC[me]==5)
{

bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GX[me]+=(-GH[me]-800+200*LV)/140*(HeldX-GX[me])/bu;
GY[me]+=(-GH[me]-800+200*LV)/140*(HeldY-GY[me])/bu;

searchshot (GX[me], GY[me], 3, 2, 6, 0);
GH[me]-=3;

if (GH[me]<-2400)
{
ee (0, 0, 49, 0);
ee (0, 0, 49, 0);
GS6=GSz[me];
createenemy (GX[me], GY[me]-15, 39, 0, 0, 0, 0, 0);
createenemy (GX[me], GY[me]+15, 40, 0, 0, 0, 0, 0);
GC[me]++;
GSz[me]=0.1;
GSzX[me]=10;
GSzY[me]=10;
LR();
bC2=20;
GC3[me]=0;
bC=40;
p=0;

damianIgnoriertFehler = AS_PlayID (504, nil);
createexplosion (1, GX[me], GY[me], 3, 0, 0, 14, 3);
G[me]=0;

P++;

}
}
}


if (GC3[me]>30)
{
if (GC[me]==10)
{
if (GC3[me]<=32)
{
GC2[me]=320+250*sin(GC4[me]*3.14/400)-GX[me];
GC5[me]=320+250*sin(GC4[me]*3.14/400)-GY[me];
}

GX[me]+=GC2[me]/40;
GY[me]+=GC5[me]/40;

if (GC3[me]>=99)
{
GC[me]=4;
GH[me]=-1200;
}


}
}


}
}
}

/*Type 39 Babuschka Teil 1*/

if (GT[me]==39)
{
if (G[me]==2)
{
GC[me]=0;
GSY[me]=-8;
G[me]=4;
}

if (G[me]==4)
{
GSz[me]=GS6;
GP[me]=88;
GY[me]+=GSY[me];
GX[me]++;

if (C0)
{
GSY[me]++;
}

if (GY[me]>=580)
{
G[me]=0;
}
}
}



/*Type 40 Babuschka Teil 2*/

if (GT[me]==40)
{
if (G[me]==2)
{
GSz[me]=GS6;
 GP[me]=89;
GY[me]+=8;
if (GY[me]>=580)
{
G[me]=0;
}
}
}

/*Type 41 Schuss*/

if (GT[me]==41)
{
if (G[me]==2)
{
GC5[me]=0;
GSz[me]=1;
GSzX[me]=40;
GSzY[me]=5;

if (GC4[me]>1)
{
GSzX[me]=GC4[me];
GSzY[me]=GC4[me];
}

GSz[me]=1;
GP[me]=GC3[me];
G[me]++;
}

if (G[me]==3)
{
GC5[me]++;
GX[me]+=GC[me]/6-LV;
GY[me]+=GC2[me]/6-LV;

bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GC[me]+=(2+1.5*LV)*(HeldX-GX[me])/bu;
GC2[me]+=(2+1.5*LV)*(HeldY-GY[me])/bu;

if (abs(GX[me]-320)>335)
{
G[me]=0;
}

if (abs(GY[me]-240)>255)
{
G[me]=0;
}

if (GC5[me]>80)
{
G[me]=0;
}

}

}





/*Type 42--------Rackete 2-----------------*/

if (GT[me]==42)
{
if (G[me]==2)
{
GP[me]=127;
GSz[me]=1;
GSzX[me]=4;
GSzY[me]=18;
damianIgnoriertFehler = AS_PlayID (2050, nil);
createexplosion (6, GX[me], GY[me]-16, 4, 0, -4, 5, 0.5);
createexplosion (6, GX[me], GY[me]-16, 4, -2, -3, 5, 0.5);
createexplosion (6, GX[me], GY[me]-16, 4, 2, -3, 5, 0.5);
G[me]++;
}
if (G[me]==3)
{

if (GY[me]>505)
{
G[me]=0;
}


GX[me]+=GC[me];
GY[me]+=GC2[me];

if (HeldX>GX[me])
{
GC[me]++;
}

if (HeldX<GX[me])
{
GC[me]--;
}


if (C==0)
{
createexplosion (6, GX[me], GY[me]-16, 3, 0, -3, 5, 0.15);
}


if (GC2[me]<=GC3[me])
{
if (C0)
{
GC2[me]+=GC4[me];
}
}

}
}



/* TYpe 43 Boss L*/

if (GT[me]==43)
{

if (G[me]==2)
{

GP[me]=93;
GSz[me]=0.06;
GSzX[me]=-100;
GSzY[me]=-100;
GC[me]=0;
GC2[me]=40;
G[me]++;
GH[me]=4000;
}


if (G[me]==3)
{

if (GH[me]<0)
{
G[me]=4;
createexplosion (8, GX[me]-100, GY[me], 3, 0, 0, 5, 2);
createexplosion (8, GX[me]+100, GY[me], 3, 0, 0, 5, 2);
createexplosion (8, GX[me], GY[me], 3, 0, 0, 5, 2);
damianIgnoriertFehler = AS_PlayID (1272, nil);
}


GP[me]==93;
GX[me]=319;
GY[me]=240-((160/0.8)*GSz[me]);

GSzX[me]=-100;
GSzY[me]=-100;


if (GSz[me]>0.7)
{
if (GSz[me]<0.9)
{
GSzX[me]=90;
GSzY[me]=50;
}
}


if (GC[me]==0)
{
GSz[me]+=GSz[me]*GC2[me]/2000;
if (GSz[me]>0.85)
{
GC[me]++;
}
}

if (GC[me]==1)
{
GSz[me]+=GSz[me]*GC2[me]/2000;
GC2[me]-=2;

if (GSz[me]<=0.8)
{
damianIgnoriertFehler = AS_PlayID (1006, nil);
GSz[me]=0.8;
GC[me]++;
}

if (GC2[me]<=-20)
{
GC2[me]=-20;
}
}


if (GC[me]==2)
{
GP[me]=93;
if (C16+C==0)
{
GP[me]=94;
searchshot (GX[me], GY[me], 10, 4, 9, 0);
damianIgnoriertFehler = AS_PlayID (15805, nil);
}
if (C==0)
{
if (rd<=10)
{
createenemy (GX[me]+50, GY[me]+10, 42, 0, 0, 2, 15, 1);
}
if (rd>5)
{
if (rd<=15)
{
createenemy (GX[me]-50, GY[me]+10, 42, 0, 0, 2, 15, 1);
}
}
}
}


}



if (G[me]==4)
{
GX[me]=319;
GY[me]=240-((160/0.8)*GSz[me]);
GSz[me]-=GSz[me]*0.015;
if (C==0)
{
createexplosion (0, GX[me]+GSz[me]*(-rd), GY[me], 1, 0, 0, 8, GSz[me]*1.5);
}
if (C==1)
{
createexplosion (0, GX[me]+GSz[me]*(rd2), GY[me], 1, 0, 0, 8, GSz[me]*1.5);
}
if (C==2)
{
createexplosion (0, GX[me]+GSz[me]*(-rd), GY[me], 1, 0, 0, 8, GSz[me]*1.5);
}
if (C==3)
{
createexplosion (0, GX[me]+GSz[me]*(rd2), GY[me], 1, 0, 0, 8, GSz[me]*1.5);
GS=100;
}
if (GSz[me]<0.03)
{
G[me]=0;
P++;
 ee (320, 240, 46, 0);
}
}

}




/*Type 44, Hilfslift*/

if (GT[me]==44)
{
if (GS>=100)
{
GH[me]-=10;
}
if (G[me]==2)
{

GP[me]=95;
GSz[me]=0.06;
GSzX[me]=-100;
GSzY[me]=-100;
GC[me]=0;
GC2[me]=40;
G[me]++;
GH[me]==280;
}


if (G[me]==4)
{

GX[me]=319+(GC4[me]*((125/0.5)*GSz[me]));
GY[me]=240-((180/0.5)*GSz[me]);


GSz[me]-=0.03*GSz[me];
createexplosion (0, GX[me]+GSz[me]*(-50+rd), GY[me]+GSz[me]*(-50+rd2), 2, 0, 0, 8, GSz[me]*1.5);
if (GSz[me]<0.05)
{
GSz[me]=0.06;
GSzX[me]=-100;
GSzY[me]=-100;
GC[me]=0;
GC2[me]=50;
G[me]=3;
GH[me]=480;
damianIgnoriertFehler = AS_PlayID (25339, nil);
if (GS>=100)
{
G[me]=0;
}
}
}


if (G[me]==3)
{


if (GH[me]<0)
{
G[me]=4;
createexplosion (8, GX[me]-50+rd, GY[me]-50+rd2, 2, 0, 0, 5, 1);
damianIgnoriertFehler = AS_PlayID (1270, nil);
}

GP[me]==93;
GX[me]=319+(GC4[me]*((125/0.5)*GSz[me]));
GY[me]=240-((180/0.5)*GSz[me]);

GSzX[me]=-100;
GSzY[me]=-100;

if (GSz[me]>0.4)
{
if (GSz[me]<0.6)
{
GSzX[me]=40;
GSzY[me]=40;
}
}

if (GC[me]==0)
{
GSz[me]+=GSz[me]*GC2[me]/2000;
if (GSz[me]>0.6)
{
GC[me]++;
}
}

if (GC[me]==1)
{
GSz[me]+=GSz[me]*GC2[me]/2000;
GC2[me]-=3;

if (GSz[me]<=0.5)
{
GSz[me]=0.5;
GC[me]++;
}

if (GC2[me]<=-20)
{
GC2[me]=-20;
}
}

if (GC[me]==2)
{
GP[me]=95;
if (C16+C==0)
{
GP[me]=98;
}
if (C==0)
{
if (C64==0)
{
if (C16+C4==0)
{
degree (me, GX[me], GY[me]);
}
damianIgnoriertFehler = AS_PlayID (20090, nil);
degreeshot (GX[me], GY[me], GC5[me], 18, 8, 3);
}
}
}
}
}



/*Type 45: MUSE Dekoration*/

if (GT[me]==45)
{
if (G[me]==2)
{
GSX[me]=GC[me];
GSY[me]=GC2[me];
G[me]=4;
GSz[me]=0.5;
GP[me]=99;
}
if (G[me]==4)
{
bu=(sqrt(((320-GX[me])*(320-GX[me]))+((240-GY[me])*(240-GY[me]))));
GSX[me]+=0.5*(320-GX[me])/bu;
GSY[me]+=0.5*(240-GY[me])/bu;

GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (GS==10)
{
G[me]++;
}
}


if (G[me]==5)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (GC3[me]++>100)
{
G[me]=0;
}
}
}




/*Type 46, Spec Explosion*/

if (GT[me]==46)
{
if (G[me]==2)
{
damianIgnoriertFehler = AS_PlayID (504, nil);
GSz[me]=0.08;
G[me]=4;
GC[me]=80;
}
if (G[me]==4)
{

GP[me]=117;
if (C0)
{
GP[me]=118;
}

GSz[me]+=GC[me]*0.0012;
if (GSz[me]>3)
{
GC[me]-=12;
 }
if (GSz[me]<0.03)
{
G[me]=0;
}
}
}


/*Type 49: Positionshilfsgegner*/

if (GT[me]==49)
{
if (G[me]==2)
{
GP[me]=149;
if (GC[me]++>10)
{
G[me]=0;
}
}
}








/*Type 50 letzter Boss*/

if (GT[me]==50)
{

if (C4==0)
{
GP[me]=105+C;
}

if (C4==1)
{
GP[me]=107+C;
}

if (C4==2)
{
GP[me]=105+C;
}

if (C4==3)
{
GP[me]=107+C;
}


if (G[me]==1)
{
GSzX[me]=50;
GSzY[me]=50;
GSz[me]=0.05;
GP[me]=105;
}

if (G[me]==2)
{
GSz[me]=GSz[me]*1.03;
GH[me]=4000;
if (GSz[me]>=0.98)
{

G[me]=3;
}
}

if (G[me]==3)
{

/*if ((int)TickCount()-snd5>=2100)
{
snd5=(int)TickCount();
damianIgnoriertFehler = AS_PlayID (14151, nil);
}*/
	
	
if (GH[me]>2800)
{
GSX[me]=(HeldX-GX[me])/bu;
GX[me]+=((5000-GH[me])/400)*GSX[me];

if (C==0)
{
degreeshot (GX[me], GY[me], 50+rd, 6, 5, 1);
}

}


if (GH[me]<=2800)
{
if (GH[me]>1400)
{

bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(HeldX-GX[me])/bu;
GSY[me]=(HeldY-GY[me])/bu;

if (GC4[me]==0)
{
GC4[me]=1575;
bgS=0;
bgC=3;
bgP=19;
}

if (LV>0)
{
if (C0)
{
degreeshot (GX[me], GY[me], GC3[me], 15, 2, 0);
degreeshot (GX[me], GY[me], GC3[me]-200, 15, 2, 0);
}
}

if (LV<=0)
{
if (C<=1)
{
degreeshot (GX[me], GY[me], GC3[me], 15, 2, 0);
degreeshot (GX[me], GY[me], GC3[me]-200, 15, 2, 0);
}
}

if (GX[me]<310)
{
GX[me]+=2;
}
if (GX[me]>330)
{
GX[me]-=2;
}
if (GY[me]<230)
{
GY[me]+=2;
}
if (GY[me]>250)
{
GY[me]-=2;
}
GC[me]=0;
}

GC3[me]+=(3400-GH[me])/(230-30*LV);


}

if (GH[me]<=1400)
{

if (GC4[me]==0)
{
GC4[me]=1575;
bgS=0;
bgC=3;
bgP=19;
}

if (C<=2+LV)
{
degreeshot (GX[me], GY[me], rd*4, (int)((5000-GH[me])/300), 2, 0);
}

if (GC[me]++>=55-15*LV)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=(HeldX-GX[me])/bu;
GSY[me]=(HeldY-GY[me])/bu;
GC[me]=0;
}

if (abs(GSX[me]<2))
{
GX[me]+=((5000-GH[me])/450-50*LV)*GSX[me];
}

if (abs(GSY[me]<2))
{
GY[me]+=((5000-GH[me])/450-50*LV)*GSY[me];
}

}

if (GH[me]<0)
{
G[me]=4;
stopsound();
DaLoadFile (141);
damianIgnoriertFehler = AS_PlayID (8894, nil);
GS=1000;
FPS=5;
}

}

if (G[me]==4)
{
if (C0)
{
damianIgnoriertFehler = AS_PlayID (1270, nil);
}
createexplosion (8, GX[me]+rd-50, GY[me]+rd2-50, 2, 0, 0, 6, 1);
if (GC2[me]>80)
{
HY[0]-=12;
HY[1]-=12;
Held=0;
}
if (GC2[me]++>150)
{
G[me]=0;
damianIgnoriertFehler = AS_PlayID (504, nil);
G[me]=10;
}

}

if (G[me]==10)
{
GSz[me]=GSz[me]*1.08;
if (GSz[me]>=50)
{

Pic[8] = GetPicture(1603);
boundsB[8] = ((**Pic[8]).picFrame);
OboundsB[8] = ((**Pic[8]).picFrame);	

G[me]=0;
FPS=3;
L=9;
ko=0;
createenemy (-180, 100, 51, 640, 0,0,0,8);
createenemy (-50, 100, 51, 640, 0,0,0,8);
createenemy (690, 100, 51, 640, 0,0,0,-8);
createenemy (820, 100, 51, 640, 0,0,0,-8);
}
}

}





/*Type 51 T�nzer*/


if (GT[me]==51)
{
if (G[me]==2)
{
GSz[me]=1;
Held=0;
HeldX=-1000;
GP[me]=84;
GC[me]++;
GY[me]+=10;
GX[me]+=GC4[me];

if (GC[me]>=30)
{
G[me]++;
GC[me]=0;
}
}

if (G[me]==3)
{
GC[me]++;
GP[me]=C4+82;

if (GC[me]>=300)
{
G[me]++;
}
}

if (G[me]==4)
{
if (C16<=1)
{
GX[me]+=4;
GP[me]=82;
}

if (C16>1)
{
GX[me]-=4;
GP[me]=83;
}

bC=51;
if (GC[me]++>600)
{
G[me]=0;
bC=0;
}

}
}



/*Type 52 Wasserexplosion*/

if (GT[me]==52)
{
if (G[me]==2)
{
GP[me]=161;
GSz[me]=1.5;
G[me]=4;
GSX[me]=GC[me];
GSY[me]=GC2[me];
}

if (G[me]==4)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

GSX[me]+=GC3[me]/10;
GSY[me]+=GC4[me]/10;
if (GC5[me]++>=abs(GA[me]))
{
GP[me]++;
GC5[me]=-1; 
}
if (GP[me]>=168)
{
G[me]=0;
}
}
}


/*Type 53 Wasserexplosion klein*/

if (GT[me]==53)
{
if (G[me]==2)
{
GP[me]=161;
GSz[me]=1;
G[me]=4;
GSX[me]=GC[me];
GSY[me]=GC2[me];
}

if (G[me]==4)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

GSX[me]+=GC3[me]/10;
GSY[me]+=GC4[me]/10;
if (GC5[me]++>=abs(GA[me]))
{
GP[me]++;
GC5[me]=-1; 
}
if (GP[me]>=168)
{
G[me]=0;
}
}
}


/*Type 54, kleiner Fisch 1*/

if (GT[me]==54)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=40;
GSzY[me]=60;
GH[me]=80;
G[me]++;
play (0, 122);
createenemy (GX[me], GY[me], 53, -1, -9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 0, -12, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 9, -9, -1, 20);
GP[me]=155;
GSY[me]=-16;
}

if (G[me]==3)
{

if (GH[me]<0)
{
play (0, 201);
createexplosion (8, GX[me], GY[me], 1, 0, 0, 6, 1);
GSX[me]=0;
G[me]=4;
}

if (GC[me]==0)
{
GY[me]-=16;
if (GY[me]<=(5*rd)-180)
{
GSY[me]=-16;
GSzX[me]=60;
GSzY[me]=40;
if (HeldX>GX[me])
{
GC[me]=1;
GP[me]=157;
GSY[me]=-16;
}
if (HeldX<=GX[me])
{
GC[me]=2;
GP[me]=154;
GSY[me]=-16;
}
}
}

if (GC[me]==1)
{
GY[me]+=GSY[me];
GSY[me]+=1;
GX[me]+=12;
}

if (GC[me]==2)
{
GY[me]+=GSY[me];
GSY[me]+=1;
GX[me]-=12;
}
}

if (GY[me]>500)
{
createenemy (GX[me], 480, 53, -1, -9, -9, -1, 20);
createenemy (GX[me], 480, 53, -1, 0, -12, -1, 20);
createenemy (GX[me], 480, 53, -1, 9, -9, -1, 20);
createenemy (GX[me], 480, 53, -1, -4, -11, -1, 20);
createenemy (GX[me], 480, 53, -1, 4, -11, -1, 20);
play (0,129);
G[me]=0;
}

if (G[me]==4)
{
GP[me]=154+C;
GY[me]+=GSY[me];
GSY[me]+=2;
if (GY[me]>480)
{
createenemy (GX[me], GY[me], 53, -1, -9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 0, -12, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, -4, -11, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 4, -11, -1, 20);
play (0,129);
G[me]=0;
}
}
}


/*Type 55, kleiner Fisch 2*/

if (GT[me]==55)
{
if (G[me]==2)
{
GSz[me]=0.5;
GSzX[me]=30;
GSzY[me]=30;
GH[me]=40;
G[me]++;
play (0,122);
createenemy (GX[me], GY[me], 53, -1, -9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 0, -12, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 9, -9, -1, 20);
GP[me]=155;
GSY[me]=-20;
}

if (G[me]==3)
{

if (GH[me]<0)
{
play (0, 201);
createexplosion (8, GX[me], GY[me], 1, 0, 0, 6, 1);
GSX[me]=0;
G[me]=4;
}

if (GC[me]==0)
{
GY[me]-=20;
if (GY[me]<=rd3)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]=20*(HeldX-GX[me])/bu;
GSY[me]=(20*(HeldY-GY[me])/bu)-3;
GC[me]=1;

if (GX[me]>HeldX)
{
GP[me]=154;
}

if (GX[me]>HeldX)
{
GP[me]=156;
}

}
}

if (GC[me]==1)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];
if (C==0)
{
if (rd<50)
{
GSY[me]+=1;
}
}
}

if (GY[me]>500)
{
createenemy (GX[me], 480, 53, -1, -9, -9, -1, 20);
createenemy (GX[me], 480, 53, -1, 0, -12, -1, 20);
createenemy (GX[me], 480, 53, -1, 9, -9, -1, 20);
createenemy (GX[me], 480, 53, -1, -4, -11, -1, 20);
createenemy (GX[me], 480, 53, -1, 4, -11, -1, 20);
play (0,129);
G[me]=0;
}
}

if (G[me]==4)
{
GP[me]=154+C;
GY[me]+=GSY[me];
GSY[me]+=2;
if (GY[me]>480)
{
createenemy (GX[me], GY[me], 53, -1, -9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 0, -12, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 9, -9, -1, 20);
createenemy (GX[me], GY[me], 53, -1, -4, -11, -1, 20);
createenemy (GX[me], GY[me], 53, -1, 4, -11, -1, 20);
play (0,129);
G[me]=0;
}
}
}


/*Type 56 Real Big Fish*/

if (GT[me]==56)
{
if (G[me]==2)
{
FPS=3;
snd4=0;
ko=0;
snd5=(int)TickCount();

GH[me]=4000;
GSz[me]=1;
GSzX[me]=80;
GSzY[me]=120;

stopsound ();

text (24, 8, 320, 240, 0);
text (40, 8, 320, 240, 0);
text (56, 8, 320, 240, 0);
text (72, 8, 320, 240, 0);
text (88, 8, 320, 240, 0);
text (100, 100, 320, 300, 7);
	
	play (24,18938);
	play (40,18938);
	play (56,18938);
	play (72,18938);
	play (88,18938);
	
	
DaLoadFile (152);
damianIgnoriertFehler = AS_PlayID (52, nil);
	
G[me]=5;
}

if (G[me]==5)
{
GX[me]+=GS;
GS=0;
GX[me]+=2; 
createenemy(GX[me], GY[me], 53, -1, (55-rd)/3, (20-rd2)*0.25, -25, 12);
if (GX[me]>=520) 
{
 GX[me]=520;
GY[me]=300;
G[me]=3;



play (0, 205);
ee (0, 0, 49, 0);

	createenemy(505, 330, 52, -3, -8, -5, 0, 12);
	createenemy(505, 450, 52, -3, -8, -5, 0, 12);
	createenemy(505, 290, 52, -3, -8, -5, 0, 12);
	createenemy(505, 170, 52, -3, -8, -5, 0, 12);
	createenemy(505, 210, 52, -3, -8, -5, 0, 12);
	createenemy(505, 250, 52, -3, -8, -5, 0, 12);
	createenemy(505, 370, 52, -3, -8, -5, 0, 12);
	createenemy(505, 410, 52, -3, -8, -5, 0, 12);
	
	createenemy(530, 330, 52, -3, 8, -5, 0, 12);
	createenemy(530, 450, 52, -3, 8, -5, 0, 12);
	createenemy(530, 290, 52, -3, 8, -5, 0, 12);
	createenemy(530, 170, 52, -3, 8, -5, 0, 12);
	createenemy(530, 210, 52, -3, 8, -5, 0, 12);
	createenemy(530, 250, 52, -3, 8, -5, 0, 12);
	createenemy(530, 370, 52, -3, 8, -5, 0, 12);
	createenemy(530, 410, 52, -3, 8, -5, 0, 12);
	
	createenemy(517, 330, 52, -3, -1, -7, 0, 12);
	createenemy(517, 450, 52, -3, 1, -7, 0, 12);
	createenemy(517, 290, 52, -3, -1, -7, 0, 12);
	createenemy(517, 170, 52, -3, 1, -7, 0, 12);
	createenemy(517, 210, 52, -3, -1, -7, 0, 12);
	createenemy(517, 250, 52, -3, 1, -7, 0, 12);
	createenemy(517, 370, 52, -3, -1, -7, 0, 12);
	createenemy(517, 410, 52, -3, 1, -7, 0, 12);
	
	
	createenemy(505, 330, 52, -3, -3, -5, 0, 12);
	createenemy(505, 450, 52, -3, -3, -5, 0, 12);
	createenemy(505, 290, 52, -3, -3, -5, 0, 12);
	createenemy(505, 170, 52, -3, -3, -5, 0, 12);
	createenemy(505, 210, 52, -3, -3, -5, 0, 12);
	createenemy(505, 250, 52, -3, -3, -5, 0, 12);
	createenemy(505, 370, 52, -3, -3, -5, 0, 12);
	createenemy(505, 410, 52, -3, -3, -5, 0, 12);
	
	createenemy(530, 330, 52, -3, 3, -5, 0, 12);
	createenemy(530, 450, 52, -3, 3, -5, 0, 12);
	createenemy(530, 290, 52, -3, 3, -5, 0, 12);
	createenemy(530, 170, 52, -3, 3, -5, 0, 12);
	createenemy(530, 210, 52, -3, 3, -5, 0, 12);
	createenemy(530, 250, 52, -3, 3, -5, 0, 12);
	createenemy(530, 370, 52, -3, 3, -5, 0, 12);
	createenemy(530, 410, 52, -3, 3, -5, 0, 12);
}
}

if (G[me]==3)
{
if (GC[me]==0)
{
if (GC2[me]>6)
{
GP[me]=150;
}

if (GC2[me]>35)
{
if (C4>=2)
{
GP[me]=158;
}
if (C4<=1)
{
GP[me]=159;
}
}

if (GC2[me]++>90)
{
GC[me]=1;
GSY[me]=-20;
}
}

if (GC[me]==1)
{

if (rd<(4000-GH[me])/500-(100*LV))
{
if (C==0)
{
createenemy (GX[me], GY[me], 58, 0, 100, 10, 0, 0);
}
}



GX[me]-=GC4[me];
GY[me]+=GSY[me];
GSY[me]++;

if (GSY[me]>0)
{
GP[me]=152;
}

if (GSY[me]<0)
{
GP[me]=151;
}

if (GSY[me]>0)
{
if (GY[me]>500)
{
GC[me]=3;
GC3[me]=rd4;
GP[me]=0;

play (0, 129);
}
}
}


if (GC[me]==2)
{

if (rd<(4000-GH[me])/25)
{
if (C==0)
{
createenemy (GX[me], GY[me], 58, 0, 100, 10, 0, 0);
}
}

if (GSY[me]>0)
{
GP[me]=152;
}

if (GSY[me]<0)
{
GP[me]=151;
}


GX[me]+=GC4[me];
GY[me]+=GSY[me];
GSY[me]++;

if (GSY[me]>0)
{
GP[me]=171;
}

if (GSY[me]<0)
{
GP[me]=172;
}

if (GSY[me]>0)
{
if (GY[me]>500)
{
play (0, 129);
GC[me]=3;
GC3[me]=rd4;
}
}
}

if (GC[me]==3)
{



createenemy(GX[me], 460, 53, -1, (55-rd)/3, (20-rd2)*0.25, -25, 12);
GY[me]=500;

if ((6*GC3[me])-60>GX[me])
{
GX[me]+=8;
}

if ((6*GC3[me])-60<GX[me])
{
GX[me]-=8;
}

if ((GC3[me]*6)-60<GX[me]+20)
{
if ((GC3[me]*6)-60>GX[me]-20)
{
play (0, 205);
GC4[me]=(rd/5)-3;
if (HeldX<GX[me])
{
GC[me]=1;
GSY[me]=(22+(rd2/10))*(-1);
}

if (HeldX>=GX[me])
{
GC[me]=2;
GSY[me]=(22+(rd2/10))*(-1);
}

}
}

if (ko>=2300)
{
GC[me]=4;
GY[me]=600;
GH[me]=3200;
}

if (GH[me]<=3000)
{
GC[me]=4;
GY[me]=600;
}

}


if (GC[me]==4)
{
if (GX[me]<520)
{
GX[me]+=10;
}

if (GX[me]>550)
{ 
GX[me]-=10;
 } 

GP[me]=173;
if (bC1>-96)
{
bC1--;
if (bC2>-80)
{
if (bC1<40)
{
bC2--;
}
}
GY[me]--;
}
if (bC1<=-95)
{
GC[me]=5;
GC4[me]=0;
GH[me]=3000;
}
}





if (GC[me]==5)
{

if (GH[me]<=1300)
{
G[me]=4;
}

if (GH[me]>2000)
{
if (C16<=1)
{
if (GC4[me]==0)
{
GY[me]-=abs((4200-GH[me])/300);
if (GY[me]<60)
{
GC4[me]=1;
}
}

if (GC4[me]==1)
{
GY[me]+=abs((4200-GH[me])/300);
if (GY[me]>420)
{
GC4[me]=0;
}
}

}
}

if (GH[me]<2000)
{

if (GC4[me]==0)
{
GY[me]-=(6000-GH[me])/150;
if (GY[me]<60)
{
GC4[me]=1;
}
}

if (GC4[me]==1)
{
GY[me]+=(6000-GH[me])/150;
if (GY[me]>420)
{
GC4[me]=0;
}
}

}

if (C16+C4==0)
{
play (0, 10010);
createshot (GX[me]-80, GY[me], -25, 0, 3, 0, 0);
}

if (GH[me]<2000)
{
if (C4==0)
{
if (C16==2)
{
createshot (GX[me]-80, GY[me], -25, 0, 3, 0, 0);
}
}
}

if (GH[me]>2000)
{
if (C4+C==1)
{
createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -14, 14);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -14, -14);

createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -16, 8);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -16, -8);

createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -18, 4);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -18, -4);
}

if (C==0)
{
if (C4==2)
{
createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -15, 12);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -15, -12);
createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -19, 6);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -19, -6);

/*createenemy (GX[me]-80, GY[me]+50, 58, 0, 100, 0, -10, 1);
createenemy (GX[me]-80, GY[me]-50, 58, 0, 100, 0, -10, -1);*/
}
}
}

}

}


if (G[me]==4)
{
GP[me]=158+C0;
GY[me]+=2;
if (C0)
{
createexplosion (8, GX[me]-100+2*rd, GY[me]-80+1.6*rd2, 2, 0, 0, 6, 1);
}

if (GY[me]==600)
{
play (0, 204);
play (0, 10000);
}

if (GY[me]==601)
{
play (0, 204);
play (0, 10000);
}


if (GY[me]>730)
{
G[me]=6;
P=2;

stopsound ();
DaLoadFile (153);
damianIgnoriertFehler = AS_PlayID (53, nil);

ee(-50, 270, 60, ko+2000);
ee(-50, 270, 62, ko+3100);

createenemy (700, 0, 59, ko+10, 320, -9, 0, 0);
createenemy (700, 0, 59, ko+10, 400, -9, 0, 0);
createenemy (700, 0, 59, ko+10, 480, -9, 0, 0);
createenemy (700, 0, 59, ko+10, 560, -9, 0, 0);
createenemy (700, 0, 59, ko+10, 640, -9, 0, 0);

createenemy (700, 100, 7, ko+280, -8, 2, -2, 6); 
createenemy (700, 400, 7, ko+300, -8, 2, -10, -1); 

createenemy (700, 100, 7, ko+280, -8, 2, -2, 6); 
createenemy (700, 400, 7, ko+300, -8, 2, -10, -1); 

ee(400, 480, 54, ko+350);
ee(500, 480, 54, ko+380);

createenemy (700, 100, 8, ko+420, -8, 0, 0, 0); 
createenemy (700, 100, 7, ko+460, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+500, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+540, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+580, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+620, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+660, -8, -1, 1, 8);
createenemy (700, 100, 7, ko+700, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+740, -8, 0, 1, 8);
createenemy (700, 100, 8, ko+780, -8, 0, 0, 0);
createenemy (700, 100, 7, ko+820, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+860, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+900, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+940, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+980, -8, 0, 4, 5);
createenemy (700, 100, 7, ko+1020, -8, 0, 1, 8);
createenemy (700, 100, 7, ko+1060, -8, 0, 2, 7);
createenemy (700, 100, 7, ko+1100, -8, 0, 1, 8);

createenemy (700, 350, 7, ko+1040, -8, 0, 1, -8);
createenemy (700, 350, 7, ko+880, -8, 0, 1, -8);
createenemy (700, 350, 7, ko+780, -8, 0, 2, -8);
createenemy (700, 450, 8, ko+1200, -8, 0, 0, 0);
createenemy (700, 450, 7, ko+1240, -8, 0, 2, -8);
createenemy (700, 450, 7, ko+1280, -8, 0, 2, -8);
createenemy (700, 350, 7, ko+1320, -8, 0, 2, -8);
createenemy (700, 250, 7, ko+1380, -8, 0, 2, -8);
createenemy (700, 150, 7, ko+1400, -8, 0, 2, -8);

ee(200, 480, 55, ko+1000);
ee(400, 480, 55, ko+1000);


createenemy (-100, 50, 21, ko+1500, 12, 0, 0, 0); 
createenemy (-100, 150, 21, ko+1500, 12, 0, 0, 0); 
createenemy (-100, 250, 21, ko+1500, 12, 0, 0, 0); 
createenemy (-100, 350, 21, ko+1500, 12, 0, 0, 0); 
createenemy (-100, 450, 21, ko+1500, 12, 0, 0, 0); 
createenemy (-100, 0, 21, ko+1550, 12, 0, 0, 0); 
createenemy (-100, 100, 21, ko+1550, 12, 0, 0, 0); 
createenemy (-100, 200, 21, ko+1550, 12, 0, 0, 0); 
createenemy (-100, 300, 21, ko+1550, 12, 0, 0, 0); 
createenemy (-100, 400, 21, ko+1550, 12, 0, 0, 0); 

createenemy (-100, 50, 21, ko+1600, 12, 0, 0, 0); 
createenemy (-100, 150, 21, ko+1600, 12, 0, 0, 0); 
createenemy (-100, 250, 21, ko+1600, 12, 0, 0, 0); 
createenemy (-100, 350, 21, ko+1600, 12, 0, 0, 0); 
createenemy (-100, 450, 21, ko+1600, 12, 0, 0, 0); 
createenemy (-100, 0, 21, ko+1650, 12, 0, 0, 0); 
createenemy (-100, 100, 21, ko+1650, 12, 0, 0, 0); 
createenemy (-100, 200, 21, ko+1650, 12, 0, 0, 0); 
createenemy (-100, 300, 21, ko+1650, 12, 0, 0, 0); 
createenemy (-100, 400, 21, ko+1650, 12, 0, 0, 0); 

createenemy (700, 350, 9, ko+1700, -8, 0, 0, 0);
createenemy (700, 350, 9, ko+1720, -8, 0, 0, 0);
createenemy (700, 350, 9, ko+1740, -8, 0, 0, 0);



}
}



if (G[me]==6)
{

if (bC1>=100)
{
G[me]=0;
}

bC1++;
if (bC2<0)
{
bC2++;
}
}

}



/*Blasenschuss -- Type 58*/

if (GT[me]==58)
{
if (G[me]==2)
{
GH[me]=100;
GP[me]=160;
GSz[me]=GC[me]/100;
GSzX[me]=GC[me]*16/100;
GSzY[me]=GC[me]*16/100;
GSX[me]=GC3[me];
GSY[me]=GC4[me];
GC3[me]=0;
G[me]++;
}

if (G[me]==3)
{

if (GH[me]<0)
{
G[me]=0;
}

GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (GC2[me]!=0)
{
if (GC3[me]++<20)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]+=GC2[me]*0.1*(HeldX-GX[me])/bu;
GSY[me]+=GC2[me]*0.1*(HeldY-GY[me])/bu;
}
}

if (GC3[me]>150)
{
G[me]=0;
}


/*bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GX[me]+=(-GH[me]-800+200*LV)/140*(HeldX-GX[me])/bu;
GY[me]+=(-GH[me]-800+200*LV)/140*(HeldY-GY[me])/bu;*/


if (abs(320-GX[me])>350)
{
G[me]=0;
}

if (abs(240-GY[me])>270)
{
G[me]=0;
}
}
}



/*Type 59, Stupid Fish*/

if (GT[me]==59)
{
if (G[me]==2)
{
GSzX[me]=70;
GSzY[me]=80;
GP[me]=154;
GSz[me]=1;
G[me]++;
}

if (G[me]==3)
{
GY[me]=bC1*2+GC[me];
GX[me]+=GC2[me];
if (GX[me]<-80)
{
G[me]==0;
}
}
}



/*Type 60, Kriegschiff (im Hintergrund)*/

if (GT[me]==60)
{
if (G[me]==2)
{
GP[me]=168;
GSz[me]=0.8;
G[me]=4;
text (24, 8, 320, 240, 0);
text (40, 8, 320, 240, 0);
text (56, 8, 320, 240, 0);
text (72, 8, 320, 240, 0);
text (88, 8, 320, 240, 0);
text (100, 100, 320, 300, 6);
	
	play (24,18938);
	play (40,18938);
	play (56,18938);
	play (72,18938);
	play (88,18938);
}

if (G[me]==4)
{

createenemy (GX[me]-25+0.8*rd,GY[me]+36,63,0,0,-rd2/20,-12,5);


if (GC[me]==0)
{
GX[me]+=1;
if (GX[me]>=320)
{
GC[me]=1;
DaLoadFile (154);
play (0,54);

FPS=4;
snd5=(int)TickCount();
snd4=0;
ko=0;
ee(700, 270, 64, 880);
}
}

if (GC[me]==1)
{

GS2=GX[me]-39;
GS3=GY[me]-3;

if (GS4==64)
{
G[me]=5;
createexplosion (8, GX[me],GY[me],2,0,0,5,0.75);
play (0,1270);
GSY[me]=-16;
}


if (C16<=1)
{
if (C==0)
{
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,49,0);
ee(0,0,61,0);
play(0, 1260);
}
}

if (C16>0)
{
if (rd<40+20*LV)
{
ee(GX[me]+32, GY[me]-10, 62, 0);
}
}

GX[me]+=C16-1.5;

}
}


if (G[me]==5)
{
GY[me]+=GSY[me];
GX[me]+=2;

if (C0)
{
GSY[me]++;
createexplosion (0,GX[me], GY[me], 2, 0, 0, 8, 0.75);
}



if (GSY[me]>2)
{
if (GY[me]>275)
{
G[me]=0;
play (0,205);
createenemy (GX[me],GY[me],63,0,3,-3,0,5);
createenemy (GX[me],GY[me],63,0,0,-5,0,5);
createenemy (GX[me],GY[me],63,0,-3,-3,0,5);

ee(320,240,65,ko+200);
ee(320,240,66,ko+200);
createenemy (320,240,66,ko+200,200,0,0,0);
ee(320,240,67,ko+200);



Pic[30] = GetPicture(851);
	boundsB[30] = ((**Pic[30]).picFrame);
	OboundsB[30] = ((**Pic[30]).picFrame);
	
	Pic[31] = GetPicture(850);
	boundsB[31] = ((**Pic[31]).picFrame);
	OboundsB[31] = ((**Pic[31]).picFrame);
	
	Pic[32] = GetPicture(852);
	boundsB[32] = ((**Pic[32]).picFrame);
	OboundsB[32] = ((**Pic[32]).picFrame);
	
	Pic[33] = GetPicture(853);
	boundsB[33] = ((**Pic[33]).picFrame);
	OboundsB[33] = ((**Pic[33]).picFrame);
	
	Pic[34] = GetPicture(854);
	boundsB[34] = ((**Pic[34]).picFrame);
	OboundsB[34] = ((**Pic[34]).picFrame);
P=-10;
}
}
}
}


/*Type 61, 3D-Schuss*/

if (GT[me]==61)
{
if (G[me]==2)
{
GSz[me]=0.1;
GP[me]=175;
G[me]=4;
GC2[me]=GS2;
GC3[me]=HeldX/1.1;
GC4[me]=HeldY/1.1;
}

if (G[me]>=3)
{
GSz[me]+=0.2*GSz[me];
GX[me]=((GSz[me]-0.1)*GC3[me])+((1.1-GSz[me])*GC2[me])+15*(GSz[me]-0.1);
GY[me]=((GSz[me]-0.1)*GC4[me])+((1.1-GSz[me])*GS3)+15*(GSz[me]-0.1);
 
if (GSz[me]>=1)
{
G[me]=3;
GSzX[me]=25;
GSzX[me]=25;
}

if (GSz[me]>=1.5)
{
G[me]=0;
}

}
}

if (GT[me]==62)
{
if (G[me]==2)
{
GSz[me]=0.2;
GP[me]=176;
G[me]=4;
}
if (G[me]==4)
{
GY[me]-=4;
if (GY[me]<-150)
{
createshot ((rd*7)-30, -5, 0, 10, 3, 6, 0);
G[me]=0;
}
}
}


/*GT64 Felsen*/

if (GT[me]==64)
{
if (G[me]==2)
{
printf("%d ", GS4);
GSz[me]=0.9;
GP[me]=177;
GX[me]-=10;
GY[me]=GS3;

if (GX[me]<360)
{
GS4=64;
}

if (GX[me]<-50)
{
G[me]=0;
}
}
}


/*Type 63 Wasserexplosion sehr klein*/

if (GT[me]==63)
{
if (G[me]==2)
{
GP[me]=161;
GSz[me]=0.4;
G[me]=4;
GSX[me]=GC[me];
GSY[me]=GC2[me];
}

if (G[me]==4)
{
GX[me]+=GSX[me];
GY[me]+=GSY[me];

GSX[me]+=GC3[me]/10;
GSY[me]+=GC4[me]/10;
if (GC5[me]++>=abs(GA[me]))
{
GP[me]++;
GC5[me]=-1; 
}
if (GP[me]>=168)
{
G[me]=0;
}
}
}

/*Type 65, Technotron 2000 Main Unit*/

if (GT[me]==65)
{
if (G[me]==2)
{
GC4[me]=0;
GC3[me]=200;
GSz[me]=1;
GSzX[me]=50;
GSzY[me]=120;
GH[me]=4000;
GP[me]=180;
G[me]++;
GSX[me]=0;
GSY[me]=0;
GS=40;
GS2=0;
GS5=1;

text (24, 8, 320, 240, 0);
text (40, 8, 320, 240, 0);
text (56, 8, 320, 240, 0);
text (72, 8, 320, 240, 0);
text (88, 8, 320, 240, 0);
text (100, 100, 320, 300, 5);
	
play (24,18938);
play (40,18938);
play (56,18938);
play (72,18938);
play (88,18938);

DaLoadFile (100);
DaLoadFile (155);
play (0, 55);

}

if (G[me]==3)
{


if (GC4[me]==1)
{
if (GSY[me]++>=360)
{
GC[me]=12;
GC3[me]=-100;
}
if (GSY[me]>520)
{
GC3[me]=200;
}
}

if (GS5==0)
{
if (rd2<30)
{
if (rd==81)
{
play (0, 15004);
GS5=100;
}

if (rd==82)
{
play (0, 15005);
GS5=100;
}

if (rd==83)
{
play (0, 15006);
GS5=100;
}

if (rd==84)
{
play (0, 15007);
GS5=100;
}
}
}

if (GS5==0)
{
if (GC3[me]>=200)
{
if (rd<5)
{
GS5=-15;
createenemy (GX[me]-10, GY[me]-180, 68, 0, 100, 10, 0, 0);
}
}
}

GS=55;
GS3=GX[me];
GS4=GY[me];

if (GSX[me]==0)
{
if (GSY[me]++>60)
{
GSX[me]=1;
GC[me]=5;
GC4[me]=1;
GSY[me]=0;
}
}

if (GSX[me]==1)
{
GS2-=GC[me];
GY[me]=240-(abs(sin(GS2*3.14/200)*GS));
GX[me]-=abs(cos(GS2*3.14/200)*GS-cos((GS2-GC[me])*3.14/200)*GS);

if (GX[me]<GC3[me])
{
GSX[me]=2;
}
}


if (GSX[me]==2)
{
GS2+=GC[me];
GY[me]=240-(abs(sin(GS2*3.14/200)*GS));
GX[me]+=abs(cos(GS2*3.14/200)*GS-cos((GS2-GC[me])*3.14/200)*GS);
if (GX[me]>700)
{
GSX[me]=1;
}
}


}
}

/*Type 66, Technotron 2000 Bein*/

if (GT[me]==66)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=8;
GSzY[me]=60;
GH[me]=4000;
GP[me]=185;
G[me]++;
GSX[me]=0;
GSY[me]=0;
}

if (G[me]==3)
{
GY[me]=GS4+160+((sin((GS2+GC[me])*3.14/200))*GS);
GX[me]=GS3+((cos((GS2+GC[me])*3.14/200))*GS);
}
}


/*Type 67, Technotron 2000 Kopf*/

if (GT[me]==67)
{
if (G[me]==2)
{
GSz[me]=1;
GSzX[me]=40;
GSzY[me]=35;
GH[me]=4000;
GP[me]=181;
G[me]++;
GSX[me]=0;
GSY[me]=0;
}

if (G[me]==3)
{
GX[me]=GS3;
GY[me]=GS4-180;

if (GS5==0)
{
GP[me]=181;
}

if (GS5<0)
{
GS5++;
}

if (GS5<-5)
{
GP[me]=184;
}

if (GS5>0)
{
GS5--;
if (C0)
{
if (GC[me]==0)
{
GP[me]++;

if (GP[me]>=185)
{
GC[me]=1;
}

}

if (GC[me]==1)
{
GP[me]--;
if (GP[me]<=181)
{
GC[me]=0;
}
}
}
}
}
}


/*Technothron 2000 Fireball (68)*/

if (GT[me]==68)
{
if (G[me]==2)
{
GP[me]=160;
GSz[me]=GC[me]/100;
GSzX[me]=GC[me]*16/100;
GSzY[me]=GC[me]*16/100;
GSX[me]=GC3[me];
GSY[me]=GC4[me];
GC3[me]=0;
G[me]++;
}

if (G[me]==3)
{

GP[me]=186+C;

GX[me]+=GSX[me];
GY[me]+=GSY[me];

if (GC2[me]!=0)
{
if (GC3[me]++<20)
{
bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GSX[me]+=GC2[me]*0.1*(HeldX-GX[me])/bu;
GSY[me]+=GC2[me]*0.1*(HeldY-GY[me])/bu;
}
}

if (GC3[me]>150)
{
G[me]=0;
}


/*bu=(sqrt(((HeldX-GX[me])*(HeldX-GX[me]))+((HeldY-GY[me])*(HeldY-GY[me]))));
GX[me]+=(-GH[me]-800+200*LV)/140*(HeldX-GX[me])/bu;
GY[me]+=(-GH[me]-800+200*LV)/140*(HeldY-GY[me])/bu;*/


if (abs(320-GX[me])>350)
{
G[me]=0;
}

if (abs(240-GY[me])>270)
{
G[me]=0;
}
}
}

/**/


}

/*----------------------------------------------------------------------*/


/*Testen*/

void test (t)
{
/* Raumschiff auf Gegner*/

for (t=0; t<128; t++)
{
if (G[t]==3)
{
if (abs(HX[0]-GX[t])<15+GSzX[t])
{
if (abs(HY[0]-GY[t])<10+GSzY[t])
{
heldhit (0, 60, -1);
damianIgnoriertFehler = AS_PlayID (1220, nil);
}
}
}
}

/*Raumschiff auf Sch�sse*/

for (t=0; t<150; t++)
{
if (S[t]==1)
{
if (abs(HX[0]-SX[t])<15+SS[t])
{
if (abs(HY[0]-SY[t])<10+SS[t])
{
heldhit (0, 60, -1);
damianIgnoriertFehler = AS_PlayID (1220, nil);
}
}
}
}

/*Gegner auf Fire*/

for (t=0; t<16; t++)
{
if (F[t]==1)
{
for (h7=0; h7<128; h7++)
if (G[h7]==3)
{
if (abs(FX[t]-GX[h7])<GSzX[h7]+5)
{
if (abs(FY[t]-GY[h7])<GSzY[h7]+20)
{
createexplosion (3, FX[t], FY[t], 1, 1, 1, 3, 1);
GH[h7]-=4*FPS+1-LV;

if (snd==0)
{
damianIgnoriertFehler = AS_PlayID (1200, nil);
snd=1;
}

F[t]=0;
}
}
}
}
}

/*2P*/
/* Raumschiff auf Gegner*/

if (P2)
{
for (t=0; t<128; t++)
{
if (G[t]==3)
{
if (abs(HX[1]-GX[t])<15+GSzX[t])
{
if (abs(HY[1]-GY[t])<10+GSzY[t])
{
heldhit (1, 60, -1);
damianIgnoriertFehler = AS_PlayID (1220, nil);
}
}
}
}

/*Raumschiff auf Sch�sse*/

for (t=0; t<150; t++)
{
if (S[t]==1)
{
if (abs(HX[1]-SX[t])<15+SS[t])
{
if (abs(HY[1]-SY[t])<10+SS[t])
{
heldhit (1, 60, -1);
damianIgnoriertFehler = AS_PlayID (1220, nil);
}
}
}
}
}
}



/*---------------------------------------------------------------------*/
/*Feuer*/

void shot (s)
{
if (LT==0)
{
h6++;
h62++;


for (s=0; s<8; s++)
{
if (F[s]+F[s+8]==0)
{
if (Held)
{
if (h6>=3)
{
if (f)
{
h6=0;
F[s]=1;
FX[s]=HX[0]-25;
FY[s]=HY[0]-15;

F[s+8]=1;
FX[s+8]=HX[0]+25;
FY[s+8]=HY[0]-15;
break;
}

if (f2)
{
if (P2)
{
if (h62>=3)
{
h62=0;
F[s]=1;
FX[s]=HX[1]-25;
FY[s]=HY[1]-15;

F[s+8]=1;
FX[s+8]=HX[1]+25;
FY[s+8]=HY[1]-15;
break;
}
}
}

}
}
}
}

for (s=0; s<8; s++)
{
if (F[s]==1)
{
FY[s]-=30;

OffsetRect(&boundsB[12], FX[s]+(((boundsB[12]).left)-((boundsB[12]).right)/2), FY[s]+(-((boundsB[12]).bottom)+((boundsB[12]).top))/2);
DrawPicture(Pic[12], &boundsB[12]);
boundsB[12]=OboundsB[12];

if (FY[s]<0)
{
F[s]=0;
}
}

if (F[s+8]==1)
{
FY[s+8]-=30;

OffsetRect(&boundsB[12], FX[s+8]+(((boundsB[12]).left)-((boundsB[12]).right)/2), FY[s+8]+(-((boundsB[12]).bottom)+((boundsB[12]).top))/2);
DrawPicture(Pic[12], &boundsB[12]);
boundsB[12]=OboundsB[12];

if (FY[s+8]<0)
{
F[s]=0;
F[s+8]=0;
}
}
}
}

if (LT==1)
{
h6++;
h62++;


for (s=0; s<8; s++)
{
if (F[s]+F[s+8]==0)
{
if (Held)
{
if (h6>=4)
{
if (f)
{
h6=0;
F[s]=1;
FX[s]=HX[0];
FY[s]=HY[0]-15;

F[s+8]=1;
FX[s+8]=HX[0];
FY[s+8]=HY[0]+15;
break;
}

if (P2)
{
if (h62>=4)
{
if (f2)
{
h6=0;
F[s]=1;
FX[s]=HX[1];
FY[s]=HY[1]-15;

F[s+8]=1;
FX[s+8]=HX[1];
FY[s+8]=HY[1]+15;
break;
}
}
}

}
}
}
}

for (s=0; s<8; s++)
{
if (F[s]==1)
{
FX[s]+=30;

OffsetRect(&boundsB[12], FX[s]+(((boundsB[12]).left)-((boundsB[12]).right)/2), FY[s]+(-((boundsB[12]).bottom)+((boundsB[12]).top))/2);
DrawPicture(Pic[12], &boundsB[12]);
boundsB[12]=OboundsB[12];

if (FX[s]>650)
{
F[s]=0;
}
}

if (F[s+8]==1)
{
FX[s+8]+=30;

OffsetRect(&boundsB[12], FX[s+8]+(((boundsB[12]).left)-((boundsB[12]).right)/2), FY[s+8]+(-((boundsB[12]).bottom)+((boundsB[12]).top))/2);
DrawPicture(Pic[12], &boundsB[12]);
boundsB[12]=OboundsB[12];

if (FX[s+8]>650)
{
F[s+8]=0;
}
}
}
}
}


void drawbackground (db){}	


/*Held zeichnen und bewegen usw.*/

void drawhero ()
{
for (bu4=0; bu4<=P2; bu4++)
{
if (timev[bu4]<1)
{
bu=(((OboundsB[11].right)-(OboundsB[11].left)));
bu2=(((OboundsB[11].bottom)-(OboundsB[11].top)));
SetRect (&boundsB[11], 0, 0, (HeldSz*bu), (HeldSz*bu2));

OffsetRect(&boundsB[11], HX[bu4]+(((boundsB[11]).left)-((boundsB[11]).right)/2), HY[bu4]+(-((boundsB[11]).bottom)+((boundsB[11]).top))/2);
DrawPicture(Pic[11], &boundsB[11]);
boundsB[11]=OboundsB[11]; /*Kommt noch gr�sse hinzu!*/


}

if (timev[bu4]>0)
{
h5++;
OffsetRect(&boundsB[13], HX[bu4]+(((boundsB[13]).left)-((boundsB[13]).right)/2), HY[bu4]+(-((boundsB[13]).bottom)+((boundsB[13]).top))/2);
DrawPicture(Pic[13+h5], &boundsB[13]);
boundsB[13]=OboundsB[13];

timev[bu4]--;

if (h5==1)
{
h5=-1;
}
}
}
}

/*Sch�sse zeichnen*/

void drawshot (ds)
{
if (S[ds]==1)
{
OffsetRect(&Shbounds[SF[ds]+(SP[ds]*10)], SX[ds]+(((Shbounds[SF[ds]+(SF[ds]*10)]).left)-((Shbounds[SF[ds]+(SP[ds]*10)]).right)/2), SY[ds]+(((Shbounds[SF[ds]+(SF[ds]*10)]).top)-((Shbounds[SF[ds]+(SP[ds]*10)]).bottom)/2));
DrawPicture(Sh[SF[ds]+SP[ds]*10], &Shbounds[SF[ds]+SP[ds]*10]);
Shbounds[SF[ds]+SP[ds]*10]=OShbounds[SF[ds]+SP[ds]*10];

SX[ds]+=SXS[ds];
SY[ds]+=SYS[ds];

if (SX[ds]<=-20)
{
S[ds]=0;
}
if (SY[ds]>=500)
{
S[ds]=0;
}
if (SX[ds]>=660)
{
S[ds]=0;
}
if (SY[ds]<=-20)
{
S[ds]=0;
}
}
}

/*Held Hit*/

void heldhit (int WH, int time, int health)
{
if (timev[WH]<1)
{
HP+=health;
timev[WH]=time;
}
}




void draw ()
{}



void searchshot (int searchX, int searchY, int searchS, int searchSz, int searchP, int ac)
{
bu=(sqrt(((HeldX-searchX)*(HeldX-searchX))+((HeldY-searchY)*(HeldY-searchY))));
bu2=(sqrt(((HeldX-searchX)*(HeldX-searchX))+((HeldY-searchY)*(HeldY-searchY))));
createshot (searchX, searchY, (searchS*(HeldX-searchX)/bu2)+ac*rd/100-ac/2, (searchS*(HeldY-searchY)/bu2)-ac*rd/100+ac/2, searchSz, searchP, 0);
}


void degreeshot (int dX, int dY, float dD, float dS, int dSz, int dP)
{
createshot (dX, dY, dS*cos(dD/200*3.14), dS*sin(dD/200*3.14), dSz, dP, 0);
}

void specshot (int specX, int specY, float specD, float specS, float specSX, float specSY,  int specSz, int specP)
{
createshot (specX, specY, specSX*specS*cos(specD/200*3.14), specSY*specS*sin(specD/200*3.14), specSz, specP, 0);
}

void text (short TSp,short TCp,short TXp,short TYp,short TPp)
{
for (txt=0; txt<8; txt++)
{
if (TS[txt]<=0)
{
if (TC[txt]<=0)
{
TX[txt]=TXp;
TY[txt]=TYp;
TS[txt]=TSp;
TC[txt]=TCp;
TP[txt]=TPp;
break;
}
}
}
}


void drawtext()
{
for (txt=0; txt<8; txt++)
{
if (TS[txt]>0)
{
TS[txt]--;
}
if (TS[txt]<=0)
{
if (TC[txt]>0)
{
OffsetRect(&boundsVG[TP[txt]], TX[txt]+(((boundsVG[TP[txt]]).left)-((boundsVG[TP[txt]]).right)/2), TY[txt]+(-((boundsVG[TP[txt]]).bottom)+((boundsVG[TP[txt]]).top))/2);
DrawPicture(PicVG[TP[txt]], &boundsVG[TP[txt]]);
boundsVG[TP[txt]]=OboundsVG[TP[txt]];
TC[txt]--;
}
}
}
}


void ee (int GXmm, int GYmm, int GTmm, int GAmm)
{
createenemy (GXmm, GYmm, GTmm, GAmm, 0, 0, 0, 0);
}


void bg ()
{
bgS--;
if (bgS<=0)
{
if (bgC>=0)
{
bgC--;
DrawPicture(Pic[bgP], &boundsB[bgP]);
}
}
}

void degree (short N, short OX, short OY)
{
bu=-(OX-HeldX)/sqrt((OX-HeldX)*(OX-HeldX)+(OY-HeldY)*(OY-HeldY));		/*sin*/
bu2=-(OY-HeldY)/sqrt((OX-HeldX)*(OX-HeldX)+(OY-HeldY)*(OY-HeldY));	/*cos*/


if (bu>=0)
{
if (bu2>=0)
{
GC5[N]=asin(bu)*200/3.14;
}
if (bu2<0)
{
GC5[N]=200+(asin(bu)*200/3.14);
}
}

if (bu<0)
{
if (bu2>=0)
{
GC5[N]=400+(asin(bu)*200/3.14);
}
if (bu2<=0)
{
GC5[N]=200-(asin(bu)*200/3.14);
}
}

GC5[me]=100-GC5[me];
}


void size (float bSz, short pict)
{
bu=(((OboundsB[pict].right)-(OboundsB[pict].left)));
bu2=(((OboundsB[pict].bottom)-(OboundsB[pict].top)));
SetRect (&boundsB[pict], 0, 0, ((bSz*bu)), ((bSz*bu2)));
}


static void GetMBarRgn(RgnHandle mBarRgn)
{
	Rect			mBarRect;

	mBarRect = qd.screenBits.bounds;
	mBarRect.bottom = mBarRect.top + GetMBarHeight();
	RectRgn(mBarRgn, &mBarRect);
}

static void SH_ForceUpdate(RgnHandle rgn)
{
	WindowRef		wpFirst = LMGetWindowList();
	
	PaintBehind(wpFirst, rgn);
	CalcVisBehind(wpFirst, rgn);
}


void stopsound ()
{
AS_CloseDown();
damianIgnoriertFehler = AS_Initialise (&gSoundAchtung, 256);
}


void wait (short wait)
{

waitr=(int)TickCount();

for (bu4=0; bu4<10; bu4)
{		
if ((int)TickCount()-waitr>=wait)
{
break;
}
}
}
	
	
void SR ()
{
if (SB<=0)
{
SB=1;
text (0, 2, 520, 415, 11);
text (4, 2, 520, 415, 11);
text (8, 2, 520, 415, 11);
text (12, 2, 520, 415, 11);
text (16, 2, 520, 415, 11);
text (20, 2, 520, 415, 11);
text (24, 2, 520, 415, 11);
}
}

void LR ()
{
if (HP<=5)
{
bu=HP;
HP+=((6-HP)/4)+((4-HP)*(4-HP)/30);
if ((int)HP>(int)bu)
{
text (0, 2, 520, 400, 12);
text (4, 2, 520, 400, 12);
text (8, 2, 520, 400, 12);
text (12, 2, 520, 400, 12);
text (16, 2, 520, 400, 12);
text (20, 2, 520, 400, 12);
text (24, 2, 520, 400, 12);
}
}
}

void gameover ()
{
if (HP<0)
{
if (meine == 3)
{
damianIgnoriertFehler = AS_PlayID (5006, nil);
HP=-1000;
createexplosion (1, HX[0], HY[0], 2, 0, 0, 14, 1.5);
HX[0]=-1000;
HX[1]=-1000;

}

if (meine++>=60)
{
p=0;
HP=3;
Held=0;
L2=L;
L=10;
ko=-60;

for (bu4=0; bu4<128; bu4++)
{
G[bu4] = 0;
}

for (bu4=1; bu4<100; bu4++)
{
S[bu4] = 0;
}

meine = 0;

Pic[1] = GetPicture(133);
boundsB[1] = ((**Pic[1]).picFrame);
OboundsB[1] = ((**Pic[1]).picFrame);

Pic[2] = GetPicture(134);
boundsB[2] = ((**Pic[2]).picFrame);
OboundsB[2] = ((**Pic[2]).picFrame);

Pic[3] = GetPicture(135);
boundsB[3] = ((**Pic[3]).picFrame);
OboundsB[3] = ((**Pic[3]).picFrame);

Pic[4] = GetPicture(136);
boundsB[4] = ((**Pic[4]).picFrame);
OboundsB[4] = ((**Pic[4]).picFrame);

Pic[5] = GetPicture(137);
boundsB[5] = ((**Pic[5]).picFrame);
OboundsB[5] = ((**Pic[5]).picFrame);

Pic[6] = GetPicture(138);
boundsB[6] = ((**Pic[6]).picFrame);
OboundsB[6] = ((**Pic[6]).picFrame);

Pic[7] = GetPicture(139);
boundsB[7] = ((**Pic[7]).picFrame);
OboundsB[7] = ((**Pic[7]).picFrame);

Pic[8] = GetPicture(140);
boundsB[8] = ((**Pic[8]).picFrame);
OboundsB[8] = ((**Pic[8]).picFrame);

Pic[9] = GetPicture(141);
boundsB[9] = ((**Pic[9]).picFrame);
OboundsB[9] = ((**Pic[9]).picFrame);

Pic[10] = GetPicture(142);
boundsB[10] = ((**Pic[10]).picFrame);
OboundsB[10] = ((**Pic[10]).picFrame);

Pic[11] = GetPicture(143);
boundsB[11] = ((**Pic[11]).picFrame);
OboundsB[11] = ((**Pic[11]).picFrame);

Pic[12] = GetPicture(144);
boundsB[12] = ((**Pic[12]).picFrame);
OboundsB[12] = ((**Pic[12]).picFrame);

Pic[15] = GetPicture(1603);
boundsB[15] = ((**Pic[15]).picFrame);
OboundsB[15] = ((**Pic[15]).picFrame);
}
}
}

void list ()
{
if (Held)
{
if (SB)
{
OffsetRect(&boundsB[20], 20, 430);		
DrawPicture(Pic[20], &boundsB[20]);
boundsB[20] = OboundsB[20];
}
if (HP>=1)
{
OffsetRect(&boundsB[21], 70, 435);		
DrawPicture(Pic[21], &boundsB[21]);
boundsB[21] = OboundsB[21];
}
if (HP>=2)
{
OffsetRect(&boundsB[21], 110, 435);		
DrawPicture(Pic[21], &boundsB[21]);
boundsB[21] = OboundsB[21];
}
if (HP>=3)
{
OffsetRect(&boundsB[21], 150, 435);		
DrawPicture(Pic[21], &boundsB[21]);
boundsB[21] = OboundsB[21];
}
if (HP>=4)
{
OffsetRect(&boundsB[21], 190, 435);		
DrawPicture(Pic[21], &boundsB[21]);
boundsB[21] = OboundsB[21];
}
if (HP>=5)
{
OffsetRect(&boundsB[21], 230, 435);		
DrawPicture(Pic[21], &boundsB[21]);
boundsB[21] = OboundsB[21];
}
}
}

void reset ()
{

bild=0;
bild2=0;
bild3=0;
bild4=0;
bild5=0;
bild6=0;
bild7=0;
	
bC=0;
bC1=0;
bC2=0;
bC3=0;
bC4=0;
bC5=0;
bC6=0;
bC7=0;
	
	
for (bu=0; bu4<100; bu4++)
{
S[bu4]=0;
}
for (bu=0; bu4<128; bu4++)
{
G[bu4]=0;
}

for (bu=0; bu4<8; bu4++)
{
TS[bu4]=0;
TC[bu4]=2;
}
createshot (-15, -15, 0, 0, 0, 0, 0);
ee(0,0,36,0);
ee(0,0,37,0);
stopsound ();
}



void play (short pD, short pID)
{
for (bu4=0; bu4<8; bu4++)
{
if (PD[bu4]<0)
{
PD[bu4]=pD;
PID[bu4]=pID;
break;
}
}
}



void playsound ()
{
for (bu4=0; bu4<8; bu4++)
{
if (PD[bu4]--==0)
{
damianIgnoriertFehler = AS_PlayID (PID[bu4], nil);
}
}
}
/*FERTIG*/





/************************************* FILES_MOD vom dorian *****************************************************/
/* 	Zweck: Resources im File <name> im selben Order wie das Programm k�nnen auch geladen werden					*/
/*			wobei <name> der Inhalt der 'STR '-Resource mit der ID 128 ist										*/
/*																												*/
/*	Wenn doppelte Resourcen vorhanden sind (d.h. gleiche ID im Programm und im Datenfile), wird diejenige		*/
/*	aus dem Datenfile geladen...glaube ich																		*/
/****************************************************************************************************************/
	
	
void DaLoadFile	(short str)
{
	int daFile;
	OSErr ignore;
	FSSpec daSpec, newSpec;
	FSRef daRef;
	
	ignore = FSGetForkCBInfo(CurResFile(), 0, nil, nil, nil, &daRef, nil);
	ignore = FSGetCatalogInfo(&daRef, kFSCatInfoNone, nil, nil, &daSpec, nil);
	ignore = FSMakeFSSpec(daSpec.vRefNum, daSpec.parID, *(GetString(str)), &newSpec);  
	daFile = FSpOpenResFile(&newSpec, fsRdWrPerm);
	
	UseResFile(daFile);
}
	
/**************************************** Ende FILES_MOD *********************************************************/
