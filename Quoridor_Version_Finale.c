#include "graphics.h"

POINT p,p1,p2,p3,p4,pj1,pj2,c1,c2,c3,c4,c5,c6,c7,c8,debut,choix,instruction,i1,i2;
int choixfait=1;
int barriereH,barriereV,deplacement;
int joueur=1;
int ligne , colonne;
int Nbarriere1=10,Nbarriere2=10;
int colonne;
int clic;

void regles (void);
void pions_init (void);
void jeu (void);
void detection_barreH_cliquee(POINT p);
void detection_barreV_cliquee(POINT p);
POINT detection_case_cliquee(POINT p);
int posi_colonne (POINT p);
void dessiner_pion (void);
int condiVictoire (int joueur);
void instructions (POINT p);
void inter_victoire (void);

void menu (void)
{
	
init_graphics(1100,700);
int choixfait=1;
debut.x=0;
debut.y=700;
affiche_image("interface_menu.bmp", debut, 1100, 700);

while (choixfait)
{
	choix = wait_clic();
	if (choix.x>171 && choix.y>290 && choix.x<313 && choix.y<350) // on clique sur jouer
	{
		choixfait=0;
		jeu();
	}
	else if (choix.x>777 && choix.y>290 && choix.x<919 && choix.y<350)  // on clique sur règles
	{
		choixfait=2;
		regles();
		do
		{
		choix = wait_clic();
		if (choix.x>478 && choix.y>24 && choix.x<618 && choix.y<108) // puis sur jouer
		{
			choixfait=0;
			jeu();
		}
		else if (choix.x>808 && choix.y>35 && choix.x<1073 && choix.y<94) // ou sur retour menu
		{
			choixfait=0;
			menu();
		}
		} while (choixfait==2);	
	}
	else if (choix.x>478 && choix.y>109 && choix.x<619 && choix.y<168) // on clique sur quitter
	{
		exit(0);
	}
}
}

void regles (void)
{
	init_graphics(1100,700);
	debut.x=0;
	debut.y=700;
	affiche_image("interface_regles.bmp", debut, 1100, 700);
}

void pions_init (void)
{
	p1.x=287;
	p1.y=349;
	draw_fill_circle(p1, 10, red); 	// on trace le pion initial du joueur 1 = rouge
	p2=p1;
	
	p3.x=811;
	p3.y=349;	
	draw_fill_circle(p3, 10, white);	// on trace le pion initial du joueur 2	= blanc
	p4=p3;	
	pj1.x=153;pj1.y=400;
	aff_int(Nbarriere1, 30, pj1, red);
	pj2.x=1000;pj2.y=400;
	aff_int(Nbarriere2, 30, pj2, white);

	
}

void detection_barreH_cliquee(POINT p)
{	
	if (p.x>=313 && p.x<=329) { c1.x=264; c2.x=375; }
	else if (p.x>=378 && p.x<=394) { c1.x=328; c2.x=440; } 
	else if (p.x>=444 && p.x<=458) { c1.x=394; c2.x=506; }
	else if (p.x>=509 && p.x<=524) { c1.x=460; c2.x=572; }
	else if (p.x>=575 && p.x<=590) { c1.x=526; c2.x=638; }
	else if (p.x>=640 && p.x<=655) { c1.x=592; c2.x=704; }
	else if (p.x>=705 && p.x<=720) { c1.x=656; c2.x=769; }
	else if (p.x>=770 && p.x<=786) { c1.x=723; c2.x=835; }

	if (p.y>=130 && p.y<=150)  { c1.y=132; c2.y=149; }
	else if (p.y>=190 && p.y<=206) { c1.y=193; c2.y=204; }
	else if (p.y>=248 && p.y<=268) { c1.y=249; c2.y=265; }
	else if (p.y>=308 && p.y<=328) { c1.y=309; c2.y=326; }
	else if (p.y>=370 && p.y<=390) { c1.y=370; c2.y=387; }
	else if (p.y>=428 && p.y<=450) { c1.y=430; c2.y=447; } 
	else if (p.y>=489 && p.y<=511) { c1.y=491; c2.y=507; }
	else if (p.y>=550 && p.y<=570) { c1.y=552; c2.y=568; }
	
	// Pour vérifier qu'une barrière horizontale a bien été posée
	if (( !(p.x>=313 && p.x<=329) && !(p.x>=378 && p.x<=394) && !(p.x>=444 && p.x<=458) && !(p.x>=509 && p.x<=524) && !(p.x>=575 && p.x<=590) && !(p.x>=640 && p.x<=655) && !(p.x>=705 && p.x<=720) && !(p.x>=770 && p.x<=786))||( !(p.y>=130 && p.y<=150) && !(p.y>=190 && p.y<=206) && !(p.y>=248 && p.y<=268) && !(p.y>=308 && p.y<=328) && !(p.y>=370 && p.y<=390) && !(p.y>=428 && p.y<=450) && !(p.y>=489 && p.y<=511) && !(p.y>=550 && p.y<=570)))
	{
		p = wait_clic();
		detection_barreH_cliquee(p) ;
	}
}

void detection_barreV_cliquee(POINT p)
{	
	if (p.x>=313 && p.x<=329) { c1.x=313; c2.x=329; }
	else if (p.x>=378 && p.x<=394) { c1.x=378; c2.x=394; } 
	else if (p.x>=444 && p.x<=458) { c1.x=444; c2.x=458; }
	else if (p.x>=509 && p.x<=524) { c1.x=509; c2.x=524; }
	else if (p.x>=575 && p.x<=590) { c1.x=575; c2.x=590; }
	else if (p.x>=640 && p.x<=655) { c1.x=640; c2.x=655; }
	else if (p.x>=705 && p.x<=720) { c1.x=705; c2.x=720; }
	else if (p.x>=770 && p.x<=786) { c1.x=770; c2.x=786; }

	if (p.y>=130 && p.y<=150)  { c1.y=88; c2.y=190; }
	else if (p.y>=190 && p.y<=206) { c1.y=150; c2.y=248; }
	else if (p.y>=248 && p.y<=268) { c1.y=205; c2.y=307; }
	else if (p.y>=308 && p.y<=328) { c1.y=265; c2.y=369; }
	else if (p.y>=370 && p.y<=390) { c1.y=327; c2.y=428; }
	else if (p.y>=428 && p.y<=450) { c1.y=387; c2.y=488; } 
	else if (p.y>=489 && p.y<=511) { c1.y=448; c2.y=550; }
	else if (p.y>=550 && p.y<=570) { c1.y=508; c2.y=612; }
		
	// Pour vérifier qu'une barrière verticale a bien été posée
	if ((!(p.x>=313 && p.x<=329) && !(p.x>=378 && p.x<=394) && !(p.x>=444 && p.x<=458) && !(p.x>=509 && p.x<=524) && !(p.x>=575 && p.x<=590) && !(p.x>=640 && p.x<=655) && !(p.x>=705 && p.x<=720) && !(p.x>=770 && p.x<=786)) || (!(p.y>=130 && p.y<=150) && !(p.y>=190 && p.y<=206) && !(p.y>=248 && p.y<=268) && !(p.y>=308 && p.y<=328) && !(p.y>=370 && p.y<=390) && !(p.y>=428 && p.y<=450) && !(p.y>=489 && p.y<=511) && !(p.y>=550 && p.y<=570)))
	{
		p = wait_clic();
		detection_barreV_cliquee(p) ;
	}

}

POINT detection_case_cliquee(POINT p)
{	
	if (p.x>=264 && p.x<=310){ p.x=287;}
	else if (p.x>=328 && p.x<=376){ p.x=351;}
	else if (p.x>=394 && p.x<=442){ p.x=417;}
	else if (p.x>=460 && p.x<=508){ p.x=483;}
	else if (p.x>=525 && p.x<=573){ p.x=548;}
	else if (p.x>=590 && p.x<=638){ p.x=613;}
	else if (p.x>=656 && p.x<=704){ p.x=679;}
	else if (p.x>=722 && p.x<=770){ p.x=745;}
	else if (p.x>=788 && p.x<=835){ p.x=811;}

	if (p.y>=88 && p.y<=132){ p.y=110;}
	else if (p.y>=149 && p.y<=193){ p.y=171;}
	else if (p.y>=205 && p.y<=249){ p.y=227;}
	else if (p.y>=266 && p.y<=309){ p.y=288;}
	else if (p.y>=327 && p.y<=370){ p.y=349;}
	else if (p.y>=387 && p.y<=431){ p.y=409;}
	else if (p.y>=447 && p.y<=492){ p.y=469;}
	else if (p.y>=508 && p.y<=552){ p.y=530;}
	else if (p.y>=568 && p.y<=613){ p.y=590;}
	
	// Pour vérifier qu'une case a bien été choisie
	if (( !(p.x>=264 && p.x<=310) && !(p.x>=328 && p.x<=376) && !(p.x>=394 && p.x<=442) && !(p.x>=460 && p.x<=508) && !(p.x>=525 && p.x<=573) && !(p.x>=590 && p.x<=638) && !(p.x>=656 && p.x<=704) && !(p.x>=722 && p.x<=770) && !(p.x>=788 && p.x<=835))||( !(p.y>=88 && p.y<=132) && !(p.y>=149 && p.y<=193) && !(p.y>=205 && p.y<=249) && !(p.y>=266 && p.y<=309) && !(p.y>=327 && p.y<=370) && !(p.y>=387 && p.y<=431) && !(p.y>=447 && p.y<=492) && !(p.y>=508 && p.y<=552) && !(p.y>=568 && p.y<=613)))
	{
	 p = wait_clic(); p=detection_case_cliquee(p);
	}
	
	
	
	return (p);
}

int posi_colonne (POINT p)
{
	if (p.x>=264 && p.x<=310){ colonne=0;}
	else if (p.x>=328 && p.x<=376){ colonne=1;}
	else if (p.x>=394 && p.x<=442){ colonne=2;}
	else if (p.x>=460 && p.x<=508){ colonne=3;}
	else if (p.x>=525 && p.x<=573){ colonne=4;}
	else if (p.x>=590 && p.x<=638){ colonne=5;}
	else if (p.x>=656 && p.x<=704){ colonne=6;}
	else if (p.x>=722 && p.x<=770){ colonne=7;}
	else if (p.x>=788 && p.x<=835){ colonne=8;}
	
	return colonne;
}

void dessiner_pion (void)
{
	
	
	if (joueur == 1) //pour le joueur 1
	{
		draw_fill_circle(p2, 10,couleur_RGB(52,35,30)); // on efface l'ancien pion
		draw_fill_circle(p1, 10, red);	// on trace le pion dans la case sélectionnée
	}
	else // pour le joueur 2
	{
		draw_fill_circle(p4, 10, couleur_RGB(52,35,30)); // on efface l'ancien pion
		draw_fill_circle(p3, 10, white);	// on trace le pion dans la case sélectionnée		
	}
}

void jeu (void) 
{
clic=0;
init_graphics(1100,700);
debut.x=0;
debut.y=700;
affiche_image("interface_jeu_6.bmp", debut, 1100, 700);


	c7.x=365; c7.y=640;
	c8.x=560; c8.y=680;
	c5.x=570; c5.y=640;
	c6.x=794; c6.y=680;
	c3.x=803; c3.y=640;
	c4.x=1015;c4.y=680;

	pions_init ();
	
	do
	{
		draw_rectangle(c7,c8, black); // on enlève la mise en évidence sur le bouton DEPLACEMENT
		draw_rectangle(c5,c6, black); // on enlève la mise en évidence sur le bouton BARRIERE Horizontale
		draw_rectangle(c3,c4, black); // on enlève la mise en évidence sur le bouton BARRIERE Verticale
		instructions(p);
	
		do
		{
			
			p = wait_clic();
			choixfait = 0; 
			deplacement = 0;
			barriereH = 0;
			barriereV = 0;
			if (p.x>902 && p.y>18 && p.x<1081 && p.y<72) // si on clique sur le bouton du MENU
			{
				menu();
				choixfait = 1;
			}
			if (p.x>803 && p.y>640 && p.x<1015 && p.y<680) // si on clique sur le bouton BARRIERE Verticale
			{
				instructions(p);
				if ((Nbarriere1 && joueur==1) || (Nbarriere2 && joueur==2))
				{
					barriereV=1;
					draw_rectangle(c7,c8, black); // on enlève la mise en évidence sur le bouton DEPLACEMENT
					draw_rectangle(c5,c6, black); // on enlève la mise en évidence sur le bouton BARRIERE Horizontale
					if (joueur==1){draw_rectangle(c3,c4, red);} // pour entourer le bouton BARRIERE suivant le joueur
					else { draw_rectangle(c3,c4, white);}
				}
			}
			if (p.x>570 && p.y>640 && p.x<794 && p.y<680) // si on clique sur le bouton BARRIERE Horizontale
			{
				instructions(p);
				if ((Nbarriere1 && joueur==1) || (Nbarriere2 && joueur==2))
				{
					barriereH=1;
					draw_rectangle(c3,c4, black); // on enlève la mise en évidence sur le bouton BARRIERE Verticale
					draw_rectangle(c7,c8, black); // on enlève la mise en évidence sur le bouton DEPLACEMENT
					if (joueur==1) draw_rectangle(c5,c6, red); // pour entourer le bouton suivant la couleur du joueur
					else draw_rectangle(c5,c6, white);
				}
			}
			if (p.x>365 && p.y>640 && p.x<560 && p.y<680) // si on clique sur le bouton DEPLACEMENT
			{
				instructions(p);
				deplacement=1;
				draw_rectangle(c3,c4, black); // on enlève la mise en évidence sur le bouton BARRIERE Verticale
				draw_rectangle(c5,c6, black); // on enlève la mise en évidence sur le bouton BARRIERE Horizontale
				if (joueur==1) draw_rectangle(c7,c8, red); // pour entourer le bouton suivant la couleur du joueur
				else draw_rectangle(c7,c8, white);
			}
		} while (choixfait==0 && deplacement==0 && barriereH==0 && barriereV==0 && clic==0);
		
		p = wait_clic(); // et on attend que le joueur clique sur le tableau de jeu

		if (joueur==1) 
		{			
			p1=p; // on récupère la position du clic 
			
			
				if (deplacement) // et a choisi de déplacer le pion
				{	
					p1=detection_case_cliquee(p1); // pour se positionner au milieu de la case
					dessiner_pion();		 	   // pour dessiner le nouveau pion en effaçant l'ancien
					p2=p1;
					clic=condiVictoire(1);
				}
				else // sinon il place une barre
				{	
					aff_int(Nbarriere1, 30, pj1, black);
					if (barriereH)
					{
						detection_barreH_cliquee (p);
						draw_fill_rectangle(c1,c2,red);
						Nbarriere1--;
					}
					else
					{
						detection_barreV_cliquee (p);
						draw_fill_rectangle(c1,c2,red);
						Nbarriere1--;
					}
					aff_int(Nbarriere1, 30, pj1, red);

				} // fin pour placer une barre
			 // fin joueur 1
			joueur=2;
		}
		
		else
		{
			
			p3=p;
				if (deplacement) // et a choisi de déplacer le pion
				{	
					p3=detection_case_cliquee(p3); 	// pour identifier le milieu de la case
					dessiner_pion(); 			// pour dessiner le nouveau pion en effaçant l'ancien pion
					p4=p3;
					clic=condiVictoire(2);
				}
				else // sinon il place une barre
				{	
					aff_int(Nbarriere2, 30, pj2, black);
					if (barriereH)
					{	
						detection_barreH_cliquee (p);
						draw_fill_rectangle(c1,c2,white);
						Nbarriere2--;
					}
					else
					{
						detection_barreV_cliquee (p);
						draw_fill_rectangle(c1,c2,white);
						Nbarriere2--;
					}
					aff_int(Nbarriere2, 30, pj2, white);

				} // fin pour placer une barre
			// fin joueur 2
			joueur=1;
		}
	} while (clic==0);
}

void instructions (POINT p)
{
	
instruction.x=95; instruction.y=680;
i1.x=85;i1.y=680;i2.x=320;i2.y=650;

// affiche le message dès qu'on est sur jeu et si on a pas cliqué sur un bouton
if(!(p.x>803 && p.y>640 && p.x<1015 && p.y<680) && !(p.x>570 && p.y>640 && p.x<794 && p.y<680) && !(p.x>365 && p.y>640 && p.x<560 && p.y<680)) 
{
draw_fill_rectangle(i1,i2,couleur_RGB(22,27,31));
aff_pol("Que voulez vous faire ? ", 15, instruction, white);
}

// affiche le message si on clique sur déplacement
if (p.x>365 && p.y>640 && p.x<560 && p.y<680)
{
draw_fill_rectangle(i1,i2,couleur_RGB(22,27,31));
aff_pol("Veuillez selectionner une case ", 15, instruction, white);
}

// affiche le message si on clique sur une des barrières
if ((p.x>570 && p.y>640 && p.x<794 && p.y<680) || (p.x>803 && p.y>640 && p.x<1015 && p.y<680))
{
draw_fill_rectangle(i1,i2,couleur_RGB(22,27,31));
aff_pol("Veuillez poser une barriere ", 15, instruction, white);
}

}

void inter_victoire (void)
{

	clic=0; // pour activer la boucle
	
	do
	{
		choix =wait_clic();
		
		if(choix.x>347 && choix.y>321 && choix.x<494 && choix.y<379) // si on choisit rejouer
		{
		clic=1;     							// désactive la boucle
		Nbarriere1=10,Nbarriere2=10;joueur=1;	// réinitialisation des variables pour jouer
		jeu();									// lance la fonction pour jouer
		}
		else if(choix.x>628 && choix.y>321 && choix.x<768 && choix.y<379) // si on choisit quitter
		{
		clic=1;  // désactive la boucle
		exit(0); // permet de quitter le jeu
		}
	} while (clic==0);
}

int condiVictoire (int joueur)
{
POINT b1,b2;
b1.x=0;b1.y=0;b2.x=1100;b2.y=700;

posi_colonne(p);				// détecte la colonne où se trouve le pion qui vient d'être déplacé

if(joueur==1 && colonne==8)		// si le joueur 1 gagne 
	{
	draw_fill_rectangle(b1,b2,black);
	clic=1;		// désactive la boucle dans jeu
	affiche_image("interface_V1.bmp", debut, 1100, 700);	
	inter_victoire();	// permet les intéractions sur cette nouvelle interface
	}
	
	
else if(joueur==2 && colonne==0)	// si le joueur 2 gagne 
	{
	draw_fill_rectangle(b1,b2,black);
	clic=1;		// désactive la boucle dans jeu
	affiche_image("interface_V2.bmp", debut, 1100, 700);
	inter_victoire();	// permet les intéractions sur cette nouvelle interface
	}
else
	{
	clic=0;		// ne désactive pas la boucle dans jeu donc la partie continue 
	}
	
	return clic;
}


int main()
{
	menu();     		// lance le menu qui fait lien avec les autres interfaces 
	wait_clic();
	return (0);
}
