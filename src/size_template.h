// Bu şablon ile kaç adet ürün tipimiz var onu alacağız.
template<class T, size_t N>
size_t size(T (&)[N]) {
	return N; 		// deger dondurelim
}
