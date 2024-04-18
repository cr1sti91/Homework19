#include "Clase.h"

//Tema persoana si ziua de nastere

ziuaDeNastere::ziuaDeNastere(const unsigned& an, const unsigned& zi, const std::string& luna)
{
	this->an = an; 
	this->zi = zi; 
	this->luna = luna;

	//Initializarea momentului de nastere
	std::tm tm_struct = {};
	tm_struct.tm_year = this->an - 1900; 
	tm_struct.tm_mon = luna_to_num(this->luna) - 1;    
	tm_struct.tm_mday = this->zi;     

	this->momentNastere = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
		std::chrono::system_clock::from_time_t(std::mktime(&tm_struct)));
}

//Returneaza durata de viata
const std::chrono::duration<double> ziuaDeNastere::calculVarsta() const
{
	const std::chrono::duration<double> varsta = std::chrono::system_clock::now() - this->momentNastere;
	return varsta;
}

//Verifica daca un an este bisect
bool ziuaDeNastere::esteAnBisect(int an) {
	return (an % 4 == 0 && an % 100 != 0) || (an % 400 == 0);
}


//Getters
const unsigned ziuaDeNastere::get_an() const
{
	return an; 
}
const unsigned ziuaDeNastere::get_zi() const
{
	return zi;
}
const unsigned ziuaDeNastere::get_luna() const
{
	return luna_to_num(luna);
}



Persoana::Persoana(const std::string& nume, const std::string& prenume, const unsigned& zi,
	               const std::string& luna, const unsigned& an)
{
	this->nume = nume; 
	this->prenume = prenume; 
	this->birthday = ziuaDeNastere(an, zi, luna); 
}



void Persoana::afisareVarsta() const
{
	std::chrono::duration<double> durata = this->birthday.calculVarsta();

	// Obtinem secundele de viata
	using nr_lung = unsigned long long;
	nr_lung secunde = std::chrono::duration_cast<std::chrono::seconds>(durata).count();
	nr_lung zile, ore, minute;

	//Setam un punct in timp ca fiind timpul prezent
	auto timp_acum = std::chrono::system_clock::now();
	//Setam anul curent
	auto an_curent = static_cast<int>(std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(timp_acum)).year());
	//Setam luna curenta
	auto luna_curenta = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(timp_acum)).month(); 
	//Setam ziua curenta
	auto zi_curenta = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(timp_acum)).day();

	short zile_bisecte{}; 
	
	//Calculam cate zile bisecte a trait persoana
	for (int i = this->birthday.get_an(); i < static_cast<int>(an_curent); i++)
	{
		if (ziuaDeNastere::esteAnBisect(i)) 
		{
			zile_bisecte++; 
		}
	}
	if (ziuaDeNastere::esteAnBisect(static_cast<int>(an_curent)) 
		&& luna_curenta >= static_cast<std::chrono::month>(this->birthday.get_luna())
		&& zi_curenta >= static_cast<std::chrono::day>(this->birthday.get_zi()))
	{
		zile_bisecte++;
	}

	//Calculam anii
	int ani = secunde / (365 * 86400);

	//Daca durata de viata este mai mic ca un an, ziua bisecta nu trebuei folosita in calcule
	if (ani < 1)
		zile_bisecte = 0;

	//Calculam numarul de zile din anul curent
	zile = secunde / 86400 - (ani * 365 + zile_bisecte);
	//Calculam numarul de ore din anul curent
	ore = secunde / 3600 - (ani * 365 * 24 + (zile + zile_bisecte) * 24 );
	//Calculam numarul de minute din anul curent
	minute = secunde / 60 - (ani * 365 * 24 * 60 + (zile + zile_bisecte) * 24 * 60 + ore * 60);
	//Calculam numarul de secunde din anul curent
	secunde = secunde - (ani * 365 * 86400 + (zile + zile_bisecte) * 86400 + ore * 3600 + minute * 60);

	//Afisare
	std::cout << "\tVarsta: " << ani << " ani,  "
			  << "zile: " << zile << ",  "
		      << "ore: " << ore + 1 << ",  "  
			  << "minute: " << minute << ",   "
			  << "secunde: " << secunde << std::endl;

	std::cout << std::endl;
	std::cout << "   In total:" << std::endl;
	//Afisare durata de viata in diferite unitati de masura
	std::cout << "\tSecunde: " << std::chrono::duration_cast<std::chrono::seconds>(durata).count() << std::endl;
	std::cout << "\tMinute: " << std::chrono::duration_cast<std::chrono::minutes>(durata).count() << std::endl;
	std::cout << "\tOre: " << std::chrono::duration_cast<std::chrono::hours>(durata).count() << std::endl;
	std::cout << "\tZile: " << std::chrono::duration_cast<std::chrono::days>(durata).count() << std::endl;
	std::cout << "\tSaptamani: " << std::chrono::duration_cast<std::chrono::weeks>(durata).count() << std::endl;
	std::cout << "\tLuni: " << std::chrono::duration_cast<std::chrono::months>(durata).count() << std::endl;
}

//Din std::string convertim in unsigned int
unsigned ziuaDeNastere::luna_to_num(const std::string& luna)
{
	if (luna == "ianuarie") {
		return 1; 
	}
	else if (luna == "februarie") {
		return 2;
	}
	else if (luna == "martie") {
		return 3;
	}
	else if (luna == "aprilie") {
		return 4;
	}
	else if (luna == "mai") {
		return 5;
	}
	else if (luna == "iunie") {
		return 6;
	}
	else if (luna == "iulie") {
		return 7;
	}
	else if (luna == "august") {
		return 8;
	}
	else if (luna == "septembrie") {
		return 9;
	}
	else if (luna == "octombrie") {
		return 10;
	}
	else if (luna == "noiembrie") {
		return 11;
	}
	else if (luna == "decembrie") {
		return 12;
	} 
	else {
		return 0;
	}
}


//Tema masina
Masina::Masina(const std::string& marca, const std::string& model, int vitezaMax)
{
	this->marca = marca; 
	this->model = model; 
	this->vitezaMax = vitezaMax; 
	this->vitezaCurenta = 0;
}

void Masina::accelereaza(int viteza)
{
	if (viteza > this->vitezaMax) {
		std::cout << "\tNu este posibil de depasit viteza maxima!" << std::endl;
		return;
	}

	this->vitezaCurenta = viteza; 
	std::cout << "\tAccelerare!" << std::endl;
	std::cout << "\tViteza curenta este: " << this->vitezaCurenta << std::endl;
}

void Masina::franeaza()
{
	this->vitezaCurenta = 0; 
	std::cout << "\tFranare!" << std::endl;
	std::cout << "\tViteza curenta este: " << this->vitezaCurenta << std::endl;
}

void Masina::afiseazaInfo() const
{
	std::cout << "\tInformatie masina: " << std::endl;
	std::cout << "\tMarca masinii: " << this->marca << std::endl;
	std::cout << "\tModel masina: " << this->model << std::endl;
	std::cout << "\tViteza maxima: " << this->vitezaMax << std::endl;
}



//Tema jurnal de carti citite
Carte::Carte(const std::string& titlul, const std::string& autorul, const int& paginiCitite)
{
	this->titlul = titlul; 
	this->autorul = autorul; 
	this->paginiCitite = paginiCitite; 
}

void Carte::afisareInfoCarte() const
{
	std::cout << "\tTitlul: " << this->titlul << std::endl;
	std::cout << "\tAutorul: " << this->autorul << std::endl;
	std::cout << "\tNumarul de pagini citite: " << this->paginiCitite << std::endl;
}


JurnalCarti::JurnalCarti(const Carte& carte)
{
	this->jurnal.push_back(carte); 
}

void JurnalCarti::afisareInforCarte(unsigned index) const
{
	std::cout << "\t==========================================" << std::endl;
	std::cout << "\tInfo carte de pe pozitia " << index << std::endl;
	this->jurnal.at(index).afisareInfoCarte();
	std::cout << "\t==========================================" << std::endl;
}

void JurnalCarti::afisareCarti() const
{
	std::cout << "\t==========================================" << std::endl;
	for (size_t i = 0; i < this->jurnal.size(); i++)
	{
		this->jurnal.at(i).afisareInfoCarte(); 
	}
	std::cout << "\t==========================================" << std::endl;
}

void JurnalCarti::adaugareCarte() 
{
	std::cout << "\t==========================================" << std::endl;
	std::string titlul{}, autorul{};
	int paginiCitite{}; 

	std::cout << "\tIntrodu titlul cartii: "; 
	std::cin.ignore(); 
	std::getline(std::cin, titlul); 

	std::cout << "\tIntrodu autorul cartii: "; 
	std::getline(std::cin, autorul); 

	std::cout << "\tIntrodu numarul de pagini citite: "; 
	std::cin >> paginiCitite; 

	this->jurnal.push_back(Carte(titlul, autorul, paginiCitite)); 

	std::cout << "\tCartea a fost adaugata!" << std::endl;
	std::cout << "\t==========================================" << std::endl;

}

void JurnalCarti::stergereCarte(unsigned index)
{
	std::cout << "\t=================================================" << std::endl;

	this->jurnal.erase(this->jurnal.begin() + index); 
	std::cout << "\tCartea cu indexul " << index << " a fost stearsa!" << std::endl;
	std::cout << "\t=================================================" << std::endl;

}

void JurnalCarti::stergereaCartilor()
{
	std::cout << "\t==========================================" << std::endl;
	this->jurnal.clear(); 
	std::cout << "\tToate cartile au fost eliminate din jurnal!" << std::endl;
	std::cout << "\t==========================================" << std::endl;

}