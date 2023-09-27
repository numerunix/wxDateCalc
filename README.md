# wxDateCalc
Another countdown app in wxwidgets
# Installazione



[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/wxdatecalc)

# Tramite repository (consigliato)
Seguite le istruzioni all'indirizzo http://numeronesoft.ddns.net


# Tramite flatpak  (sconsigliato)
Seguite le istruzioni all'indirizzo http://numeronesoft.ddns.net:8080

# Compilazione con Flatpak
Installate flatpak con apt, aggiungete il repository uficiale, installate flatpakbuilder con flatpak poi installateflathub org.gnome.Platform//43
flathub org.gnome.Sdk//43
con flatpak e poi date il comando

flatpak run org.flatpak.Builder --repo=./repo ./build org.altervista.numerone.wxdatecalc.yml 
A questo punto il programma scaricherà e compilerà le ultime wxwidgets e l'ultimo wxdatecalc.

Infine dare il comando
flatpak run org.flatpak.Builder --user --install --force-clean ./build/ org.altervista.numerone.wxdatcalc.yml 

# Donazione

http://numerone.altervista.org/donazioni.php
