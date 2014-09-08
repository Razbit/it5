# Lajittelumenetelmiä
## Yksinkertaisia menetelmiä
### Valintalajittelu (Selection sort)
- Avaimet vektorissa V, indeksit 1, 2, ..., n
- Lajitellaan vaihtamalla avaimia keskenään seuraavasti:
    1) Vi = vektorin ensimmäinen indeksi
    2) Etsitään pienin avain vektorista väliltä Vi..Vn, olkoon paikassa Vj
    3) Vaihdetaan paikoissa Vi ja Vj olevat avaimet
    4) Vi++
    5) toistetaan 2..4, kunnes Vi=Vn
### Vaihtomenetelmä (bubble sort)
- Avaimet vektorissa V, indeksit 1, 2, ..., n
    1) Selataan vektori läpi ja verrataan aina kahta vierekkäistä
    2) Jos ne ovat väärässä järjestyksessä niin vaihdetaan paikkoja
        - Avain siirtyy vaihtojen avulla eteenpäin kunnes tulee suurempi vastaan
    3) Toistetaan kohdat 1..2 välillä V1..Vn-1 jne
        - Lopetetaan, jos ei enää tehdä yhtään vaihtoa
### 
