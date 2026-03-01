*This project has been created as part of the 42 curriculum by sevyesil.*

# ft_printf

## Açıklama

ft_printf, 42 müfredatı kapsamında geliştirilen ve C dilindeki
standart `printf` fonksiyonunun temel davranışlarını yeniden
implemente etmeyi amaçlayan bir projedir.

Bu projenin temel amacı, `printf` fonksiyonunun iç yapısını
derinlemesine anlamak, değişken sayıda argüman alabilen
fonksiyonların (`va_list`) nasıl çalıştığını kavramak ve
format string yapısının nasıl ayrıştırıldığını öğrenmektir.

Proje süresince format belirteçlerinin (`%d`, `%s`, `%p`,
`%x` vb.) nasıl işlendiği, her bir veri tipinin uygun biçimde
dönüştürülerek ekrana yazdırılması ve yazdırılan toplam
karakter sayısının doğru şekilde hesaplanması üzerine
yoğunlaşılmıştır.

---

## Projenin Hedefleri

- `printf` fonksiyonunun çalışma mantığını baştan sona kavramak,
- Değişken argümanlı fonksiyonlar (`va_list`, `va_start`,
  `va_arg`, `va_end`) hakkında yetkinlik kazanmak,
- Format string parsing sürecini öğrenmek,
- Modüler, okunabilir ve sürdürülebilir C kodu yazmak,
- Recursive ve iterative yaklaşımları dönüşüm fonksiyonlarında uygulamak,
- Yazdırılan karakter sayısını doğru şekilde yönetmek,
- 42 Norm kurallarına uygun yazılım geliştirmek.

---

## Talimatlar

- Projeyi derlemek için:

```bash
make
```
- Oluşturulan obje dosyalarını silmek için:

```bash
make clean
```
- Arşiv ve obje dosyalarını silmek için:

```bash
make fclean
```
- Kütüphaneyi temizleyip yeniden derlemek için:

```bash
make re
```
- Derleme sonucunda libftprintf.a adlı statik kütüphane
oluşturulur.

## Kullanım 

- Oluşturulan kütüphaneyi kendi projenizde kullanmak için
ft_printf.h dosyasını projenize dahil etmeniz yeterlidir.

- Derleme sırasında kütüphaneyi linkleyiniz:

```bash
cc main.c -L. -lftprintf
```

- Örnek kullanım:

```bash
ft_printf("Sayi: %d, Yazi: %s, Adres: %p\n", 42, "merhaba", &x);
```

## Kütüphanenin Detaylı Anlatımı 

ft_printf, format string’i ayrıştırarak (parse ederek)
çalışan bir yazdırma kütüphanesidir. Fonksiyonlar, tek
sorumluluk ilkesine uygun şekilde ayrılmıştır ve her
conversion türü için ayrı fonksiyonlar bulunmaktadır.

Bu yapı sayesinde kod okunabilirliği artırılmış ve
her format belirtecinin davranışı izole edilmiştir.


### 1. Ana Fonksiyon

ft_printf
- Format string’i karakter karakter okur
- % karakteriyle karşılaşıldığında conversion sürecini başlatır
- Normal karakterleri doğrudan ekrana yazdırır
- Yazdırılan toplam karakter sayısını döndürür

### 2. Format Yönlendirme (Dispatcher)

ft_which_character
- Bu fonksiyon, % karakterinden sonra gelen format
belirtecini kontrol eder ve ilgili conversion fonksiyonunu
çağırır.
-Bu yapı, ft_printf fonksiyonunun sade kalmasını sağlar
ve conversion mantığını merkezileştirir.

### 3. Conversion Fonksiyonları

Bu bölümde, her format belirteci için yazılmış olan
dönüşüm fonksiyonları yer almaktadır. Tüm conversion
fonksiyonları:

- Ekrana yazdırma işlemini gerçekleştirir
- Yazdırılan karakter sayısını int olarak döndürür

#### 3.1 Karakter ve String Conversion’ları

ft_print_char
- %c formatı için tek bir karakter yazdırır.

ft_print_str
- %s formatı için null-terminated string yazdırır.
- NULL kontrolü yapılarak güvenli yazdırma sağlanır.

#### 3.2 Sayısal Conversion’lar

ft_print_nbr
- %d ve %i formatları için signed integer yazdırır.

ft_print_unsigned
- %u formatı için unsigned integer yazdırır.

Bu fonksiyonlarda sayılar recursive veya iterative
yaklaşımlar kullanılarak basamak basamak yazdırılır.

#### 3.3 Hexadecimal Conversion’lar

ft_print_hex
- %x ve %X formatları için hexadecimal yazdırma yapar.
Küçük veya büyük harf kullanımı format belirtecine göre
belirlenir.

#### 3.4 Pointer Conversion

ft_print_ptr
- %p formatı için pointer adresini 0x önekiyle birlikte
hexadecimal formatta yazdırır.

Pointer yazdırımı sırasında, mimariden bağımsız ve güvenli
bir dönüşüm sağlamak amacıyla unsigned long veri tipi
kullanılmıştır.

## Dönüş Değeri

ft_printf fonksiyonu, ekrana yazdırılan toplam karakter
sayısını döndürür. Bu davranış, standart printf
fonksiyonu ile birebir uyumludur.

## Kaynaklar

- 42 ft_printf subject dokümanı
- C Standard Library (man pages)
- GNU libc documentation
- GeeksforGeeks
- Stack Overflow

## AI Kullanımı

Bu proje geliştirilirken yapay zekâ araçları, kavramsal
anlamayı desteklemek ve konu tekrarları yapmak amacıyla
kullanılmıştır. Fonksiyonların implementasyonu, hata
ayıklama süreci ve kod yazımı tamamen sevyesil tarafından
gerçekleştirilmiştir.

Proje, 42 akademik dürüstlük kurallarına uygun olarak
hazırlanmıştır.