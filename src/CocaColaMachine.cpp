//============================================================================
// Name        : CocaColaMachine.cpp
// Author      : Bulent Kocaman
// Version     : 1.0
// Copyright   : 2016
// Description : Coca-Cola Machine v1.0 (Home Work)
//============================================================================

#include <iostream>
#include <stdlib.h> //system("pause") için ekledim, ilginç linux'ta system() çalışmadı...
#include <string> // string
#include<limits> // numeric_limits için include ettik

// alan sabiti
using namespace std;

// sabitlerimiz
const string currency = "TL."; 		// para birimimiz TL olsun
const string brand = "Coca-Cola"; 	// makinamız ve ürünlerimiz için Markamız

// global değişkenimiz
float machine_total = 0.0; 				// hafizadaki para

// ürünümüzün sınıfını include edelim
#include "product.h" // include etmeden bu sayfa içerisinde de yazabilirdik.

#include "size_template.h" // size şablonu / arrayin boyutunu verir.

#include "cola.h" // Cola sınıfımızı include ettik

int main() {
	Cola c; //Cola adında ki sınıfımızı çağıralım. Bu sınıf Cosntructor kullanarak "product" sınıfında ki, addProduct metodu ile ürünleri oluşturacak.

	// c.displayView(); // makinamız hep aktif. bu satır işlenmeyecek.
	// main'e birşey kalmadı :/

	//system("pause"); 	// linuxte hata veriyor "sh: 1: pause: not found"
	return 0; // int 0 return edelim. main class tipini silersek return a gerek kalmaz.
}
