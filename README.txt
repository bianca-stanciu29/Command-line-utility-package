STANCIU BIANCA-ANDREEA, GRUPA 315CC
Pentru a rezolva aceasta tema a trebuit sa ma documentez destul de bine in legatura cu alocarea dinamica, acest lucru durand in jur de o saptamana pana la finalizarea acestei teme.
Cerinta 1: functia grep
-pentru a putea citi textul am folosit un vector temporar cu ajutorul caruia am alocat pe rand fiecarei linii cata memorie este necesara
-am facut un subpragram care sa contorizeze cate aparitii are cuvantul cautat intr-un sir
-cu ajutorul unui vector temporar se adauga extensia de colorare: 7 spatii inainte si 3 dupa cuvantul cautat
-se realoca spatii pentru inserarea extensiilor de colorare
-se elibereaza memoria alocata cuvantului cautat, matricei de vectori si variabilei lista_siruri

Cerinta 2: functia cut
-cu ajutorul unui vector temporar aloc eficient memoria: pentru sirul de delimitatori, pentru vectorul de indici, pentru textul citit, eliminand sfarsitul de linie 
-pentru sortarea sirului de indici am folosit algoritmul bubble sort
-am eliminat valorile identice
-am parcurs textul si am selectat fiecare cuvant in parte, am testat daca cuvantul este in vectorul de indici, iar cu ajutorul vectorului temporar am construit noul text
-prelucrez sirurile si eliberez memoria

Cerinta 3: functia sort
-am declarat un struct pentru a inregistra eficient materiile
-in functia read_situatie am citit datele pentru situatie-student:citire numar materii, note pentru fiecare materie; am alocat si am realocat memorie pentru fiecare linie, incrementand cu o dimensiune maxima de 3 si am calculat media notelor
-la sortare, am folosit algoritmul de bubble sort
-la afisare am printat matricea cu media la inceputul liniei cu 3 zecimale exacte, pe exact 10 spatii
-am eliberat memoria

Cerinta 4: functia encrypt
-am citit textul folosind un sir temporar pentru a aloca eficient si memoria, am eliberat spatiile 
suplimentare
-am parcurs fiecare linie cu un contor la inceput si unul la sfarsit, am verificat daca cuvantul este numar, iar daca nu se indeplinea conditia se codifica cuvantul
-am eliberat memoria



