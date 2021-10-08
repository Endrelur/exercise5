# 5
## Exercise 5 in IDATT2503
1. Utfør fuzzing med address sanitizer på C funksjonen dere lagdei øving 4 b)
    * Reparer feil dere finner gjennom fuzzing, eller introduser feil som oppdages gjennom fuzzing
    * Sett opp CI (Continuous Integration) løsning som utførerfuzzing med address sanitizer
        * Se instruksjoner for å kjøre fuzzing i en terminal (merk at du kan begrense antall sekunder libFuzzer skal kjøre med argumentet -max_total_time)
        * Du kan bruke docker image’et archlinux som utgangspunkt for å installere nyere llvm/clang++ med støtte for libFuzzer
