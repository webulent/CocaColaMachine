//Cola sınıfımız.
class Cola {
	product p[4]; //Private
public: // aşağısı public
	Cola(); //Yapıcı
	void screenMessage(); // kullanıcı ile iletisim
	int questionManager(); // kullanıcıya tamam mı devam mı diye soralım.
	void displayView();
	float insertMoney(float);
	float giveChange(const float, float);
};

// sınıf çağırıldığında yapıcı ile ürünleri ekleyelim.
Cola::Cola() {
	this->p[0].addProduct("Normal", 1, 100, 2.50); // normal coco cola ekleyelim
	this->p[1].addProduct("Light", 2, 20, 2.50); 	// coco cola light ekleyelim
	this->p[2].addProduct("Zero", 3, 10, 2.00); 	// coco cola zero ekleyelim
	this->p[3].addProduct("Water", 4, 2, 0.25); 	// coco cola marka su ekleyelim

	// Kullanıcı ile iletişime geçelim
	this->screenMessage();
}



// para üstü
float Cola::giveChange(const float amount_deposited, float price) {
	float change_due = amount_deposited - price; // yatirilan tutardan, yatirilmasini istediğimizi çıkaralım

	if (change_due > 0.0) { 	// tutarın yeterli olup olmadığına bakalım
		cout << endl << "######## Yatırdığınız para: " << amount_deposited << "" << currency
				<< endl; 	// kullanıcının yatırdığı parayı gösterelim
		cout << "######## Para üstü: " << change_due << "" << currency << endl; // para üstünü iade edelim
		machine_total -= change_due; // hafızada ki parayı, para üstünden çıkaralım.
	}

	return machine_total; // hafızada ki parayı döndürelim.
}



// Para girişi
float Cola::insertMoney(float price) {
	float total_deposited = 0.0; 	// toplam yatirilan
	float deposit = 0.0; 			// kullanici girecek.

	cout << "Para girişi yapınız: " << price << " " << currency << endl; // yatirilmasi gereken tutar
	//cin >> deposit; 												// yatirilan tutar

	//5 kuruştan aşağı kabul etmeyiz!!!!
	while(!(std::cin >> deposit) || ( deposit < 0.05 ) ){
	        cout << "Geçersiz para, lütfen tekrar deneyin." << endl;
	        cin.clear(); //temizledik, yeniden isteyeceğiz
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.clear();

	total_deposited += deposit; 				// toplam yatirilanı arttıralım

	while (total_deposited < price) { // kullanıcı yeterli tutarı girene kadar dönsün
		cout << "Lütfen " << (price - total_deposited) << " " << currency
				<< " daha yatırınız." << endl; // kalan tutarı isteyelim
		cin >> deposit; 				// kullanıcının girdiği tutar
		total_deposited += deposit; 	// toplam yatirilan tutar
	}

	machine_total += total_deposited;  	// yatirilan hafizadaki para
	return total_deposited; 				// toplam yatan tutar return edelim
}



void Cola::displayView() {
	int total_product = size(this->p); // kaç tip ürünümüz var?

	for (int i = 0; i < total_product; i++) { // urunleri listeleyelim
		cout << brand << ": " << endl << this->p[i].product_name << " - "
				<< this->p[i].product_stock << " adet kaldı."
				<< "Fiyatı " << this->p[i].product_price << " " << currency << " -----> Seçim kodu:  "
				<< this->p[i].product_code << endl << endl;
	}
}

void Cola::screenMessage() {
	int selection = 0; 	// seçim ilk başta default 0
	int qty = 1; 		// varsayılan adet

	int total_product = size(this->p); // kaç tip ürünümüz var?

	for (int i = 0; i < total_product; i++) { // urunleri, fiyatları ve seçim kodlarını listeleyelim.
		cout << brand << ": " << this->p[i].product_name << " - "
				<< this->p[i].product_price << " " << currency << " -----> "
				<< this->p[i].product_code << endl;
	}

	do {
		cout << "Lütfen seçim yapınız!" << endl; // kullanıcıdan seçim yapmasını istiyoruz
		cin >> selection; // kullanıcıdan seçim yapmasını isteyelim
	} while ((selection > total_product) || (selection < 1)); // koşul: kullanıcı yanlış değer girerse tekrar giriş yapmasını isteyelim

	/*
	 * Not: dizi değişkenimizin index'i sıfırdan başlıyor ama biz kullanıcıdan giriş yapmasını isterken 1 den başlatıyoruz.
	 * Yani kullanıcının girdiği değeri 1 eksilterek seçiminin indexine ulaşacağız.
	 */
	int product_index = --selection; // secilen ürünün indexini alalım

	float product_price = this->p[product_index].product_price; // kullanıcının seçtiği ürünün tutarı
	string product_name = this->p[product_index].product_name; // kullanıcının seçtiği ürünün adı
	int product_stock = this->p[product_index].product_stock; // kullanıcının seçtiği ürünün stok adedi
	//int product_code 	= this->p[product_index].product_code; // kullanıcının seçtiği ürünün kodu

	cout << endl; 											// alt satıra inelim
	cout << brand << " " << product_name << " " << product_price << " "
			<< currency << endl; 	// kullanıcıya seçimini gösterelim

	int question = 0;
	do {
		if (qty > 0 && qty > product_stock && product_stock > 0) { // istenen ürün stokta yeterli miktarda var mı? konreol edelim.
			cout	<< "Üzgünüz, bu üründen yeterli sayıda stoğumuz yok, dilerseniz "
					<< product_stock << " adet ürün satınalabilirsiniz."
					<< endl;
		} else if (product_stock <= 0) { // ürün stokta yoksa (== te yazabilirdik.)
			cout << "Üzgünüz, bu üründen stoğumuzda kalmadı." << endl; // kullanıcıyı bilgilendirelim.
			cout	<< "Başka bir ürün almak istermisiniz? (evet için 1, hayır için 2)"
					<< endl; 	// kullanıcıya tamam mı devam mı diyelim.

			// cin >> question; // kullanıcının cevabını alalım // bu işlemi aşağıda ki this->questionManager da yaptık.

			question = this->questionManager(); // kullanıcıya soru soralım. (tamam mı, devam mı)
		}
		cout << "Almak istediğiniz ürün adedini giriniz: "; // ürün adedini isteyelim
		cin >> qty; // kullanıcın girdiği ürün adedi
		cout << endl; // alt satir
	} while (product_stock < qty); // koşul: kullanıcı yanlış değer girerse tekrar giriş yapmasını isteyelim

	question = 0;
	int count = 0; // count ile kac defa islem yaptıgımızı sayacağız
	do {
		float total_price = product_price * qty; // adet * ürün fiyatı
		float amount_deposited = this->insertMoney(total_price); // kullanıcıdan para girişi yapmasını isteyelim (FN)
		this->giveChange(amount_deposited, total_price); // para üstü

		cout << endl; // alt satir
		cout << "Verilen ürünler: " << qty << " adet " << brand << " "
				<< product_name << endl; // kullanıcıyı bilgilendirelim
		cout << "Afiyet olsun. " << endl;  // afiyet olsun,

		this->p[product_index].product_stock =
				this->p[product_index].product_stock - qty; // ürünleri verdik, stok durumunu güncelleyelim
		int available_stock = this->p[product_index].product_stock; // yeni stok değerini değişkene atadık

		// SON DURUM:
		cout << endl; // alt satir
		cout << "******** " << brand << " " << product_name << " kalan: " << available_stock
				<< endl; // Kalan stok durumunu gösterelim

		question = this->questionManager(); // kullanıcıya soru soralım. (tamam mı, devam mı)

		count++; // döngüyü say
	} while (question == 1 && count < 4); // koşul
}

int Cola::questionManager() { // tamam mı devam mı diye soruyoruz
	int question = 0; // soru değişkenine default 0 atadık
	cout << "******** " << "Başka bir ürün almak istermisiniz? (evet için 1, hayır için 2)" << endl; //kullanıcıya seçim yapması için seçenek sunduk
	cin >> question; // kullanıcıdan cevap aldık

	if (question == 1) { // kullanıcı devam etmek istiyor.
		this->screenMessage(); // işlemi başa aldık
	} else if (question == 2) { // kullanıcı devam etmek istemiyor
		cout << "Bye Bye!" << endl << endl; // hoşcaçak :(
		cout
				<< "-----------------------------Sıradaki Kullanıcı----------------------"
				<< endl; // sırada ki kullanıcı için ayraç
		this->screenMessage(); // sıradaki kullanıcı için işlemi başa alıyoruz.
		system("pause"); // linuxte hata veriyor "sh: 1: pause: not found"
	}
	return question; // değer döndürelim
}
