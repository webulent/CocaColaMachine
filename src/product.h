// urun sınıfı
class product
{
   public:
		string product_name; //urunumuzun adı
		int product_code; // urunumuzun kodu (seçim kodu)
		int product_stock; // urunumuzun stok miktarı
		float product_price; // urunumuzun fiyatı
		void addProduct(string, int, int, float); // urun ekleme metodu
};

//product sınıfından bir method //product.h
void product::addProduct(string item_name, int item_code, int item_stock, float item_price) {
	product_name = item_name; 	// ürünümüzün adı
	product_code = item_code; 	// ürünümüzün kodu
	product_stock = item_stock; 	// ürünümüzün adedi.
	product_price = item_price; 	// ürünümüzün fiyatı
}
