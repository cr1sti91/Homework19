#include "Clase.h"

int main()
{
	//std::cout << std::chrono::system_clock::now() << std::endl;

	std::cout << "Tema pe acasa:" << std::endl;
	const std::string optiuni_intrare{ R"(
			1.Tema persoana si ziua de nastere
			2.Tema simulator de masini
			3.Tema jurnalul de carti citite
	)" };

	//Afisam optiunile posibile
	std::cout << "Optiuni:" << std::endl << optiuni_intrare << std::endl;

	//Citim optiunea necesara de la tastatura
	std::cout << "Introduce numarul din dreptul optiunii necesare: ";
	short optiune{};
	std::cin >> optiune;
	std::cout << std::endl;

	//Executam functia ce corespunde optiunei introduse
	switch (optiune)
	{
	case 1: 
	{
		std::string nume, prenume, luna; 
		short an, zi; 

		std::cout << "\t *******Tema varsta unei persoane******" << std::endl;

		std::cout << "\tIntrodu numele persoanei: "; 
		std::cin >> nume; 
		std::cout << "\tIntrodu prenumele persoanei: "; 
		std::cin >> prenume; 
		std::cout << "\tIntrodu data de nastere (de exemplu \"1 ianuarie 2024\"): ";
		std::cin >> zi >> luna >> an; 

		Persoana persoana(nume, prenume, zi, luna, an);

		std::cout << "\tAre loc calcularea..." << std::endl;
		std::cout << std::endl;

		persoana.afisareVarsta();
	}
	break;

	case 2:	
	{
		std::string marca, model; 
		int vitezaMax, vitezaCurenta; 
		
		std::cout << "\t *******Tema simularea unei masini******" << std::endl;
		
		std::cout << "\tIntrodu marca masinii: "; 
		std::cin >> marca; 
		std::cout << "\tIntrodu modelul masinii: "; 
		std::cin >> model; 
		std::cout << "\tIntrodu viteza maxima: "; 
		std::cin >> vitezaMax; 

		Masina masinaMea(marca, model, vitezaMax); 

		const std::string optiuni{ R"(
			1.Accelereaza
			2.Franeaza
			3.Afiseaza info
		)" };

		short input{}; 
		std::cout << "\tOptiuni: " << std::endl;
		std::cout << optiuni << std::endl; 
		std::cout << "\tOptiunea introdusa: ";
		std::cin >> input; 

		switch (input)
		{
		case 1: 
			std::cout << "\tIntrodu viteza pana la care doresti sa accelerezi: "; 
			std::cin >> input; 
			masinaMea.accelereaza(input);
			break;
		case 2: masinaMea.franeaza(); 
			break;
		case 3: masinaMea.afiseazaInfo(); 
			break;
		default: std::cout << "\tOptiune incorecta!" << std::endl;
		}
		
	}
	break;

	case 3: 
	{
		std::cout << "\t *******Tema Jurnal de carti citite******" << std::endl;

		JurnalCarti jurnalulMeu; 
		const std::string optiuni{ R"(
			1.Adaugare carte
			2.Stergere carte 
			3.Stergerea tuturor cartilor
			4.Afisare info carte
			5.Afisare info carti
			6.Inchidere jurnal
		)" };
		
		bool finalAplicatie = false; 
		while (!finalAplicatie)
		{
			std::cout << "\tOptiuni: " << std::endl;
			std::cout << optiuni << std::endl;

			int input{}; 
			std::cout << "Optiunea intrdosa: "; 
			std::cin >> input; 

			system("CLS");

			switch (input)
			{
			case 1:
			{
				jurnalulMeu.adaugareCarte(); 
			}
				break;

			case 2:
			{
				std::cout << "\tIntrodu indexul carti ce doresti sa o stergi: "; 
				std::cin >> input; 
				jurnalulMeu.stergereCarte(input); 
			} 
			break;

			case 3: 
			{
				jurnalulMeu.stergereaCartilor(); 
			} 
			break;

			case 4: 
			{
				std::cout << "\tIntrodu indexul cartii: "; 
				std::cin >> input; 
				jurnalulMeu.afisareInforCarte(input); 
			}
			break;

			case 5: 
			{
				jurnalulMeu.afisareCarti(); 
			}
			break;

			case 6: 
			{
				finalAplicatie = true;
			}
			break;

			default: std::cout << "Optiune incorecta!" << std::endl;
			}
		}
	}
	break;

	default: std::cout << "\tOptiune incorecta!" << std::endl;
	}
}

