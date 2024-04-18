#pragma once
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>



//Tema persoana si ziua de nastere
struct ziuaDeNastere
{
private: 
	//Variabile membru
	unsigned an{};
	unsigned zi{};
	std::string luna{};
	std::chrono::time_point<std::chrono::system_clock> momentNastere{};

public: 
	//Constructori
	ziuaDeNastere() = default;
	ziuaDeNastere(const unsigned& an, const unsigned& zi, const std::string& luna);

	//Metode
	const std::chrono::duration<double> calculVarsta() const;

	static bool esteAnBisect(int an);
	static unsigned luna_to_num(const std::string& luna);

	const unsigned get_an() const;
	const unsigned get_zi() const;
	const unsigned get_luna() const;
};


class Persoana
{
private:
	//Variabile membru
	std::string nume{};
	std::string prenume{};
	ziuaDeNastere birthday{};

public:
	//Constructori
	Persoana() = default;
	Persoana(const std::string& nume, const std::string& prenume, const unsigned& zi,
			 const std::string& luna, const unsigned& an);

	//Metode
	void afisareVarsta() const; 
};



class Masina
{
private: 
	//Variabile membru 
	std::string marca{};
	std::string model{};
	int vitezaMax{};
	int vitezaCurenta{};

public: 
	//Constructori
	Masina() = default;
	Masina(const std::string& marca, const std::string& model, int vitezaMax); 

	//Metode
	void accelereaza(int viteza); 
	void franeaza();
	void afiseazaInfo() const;
};



class Carte
{
private:
	//Variabile membru
	std::string titlul; 
	std::string autorul; 
	int paginiCitite; 

public: 
	//Constructor
	Carte(const std::string& titlul, const std::string& autorul, const int& paginiCitite); 

	//Metode
	void afisareInfoCarte() const; 
};

class JurnalCarti
{
private:
	//Variabile membru
	std::vector<Carte> jurnal{};

public:
	//Constructori
	JurnalCarti() = default;
	JurnalCarti(const Carte& carte); 

	//Metode
	void afisareCarti() const; 
	void afisareInforCarte(unsigned index) const; 
	void adaugareCarte(); 
	void stergereCarte(unsigned index); 
	void stergereaCartilor(); 

};