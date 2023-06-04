# wxDateCalc
Another countdown app in wxwidgets
# Installazione



[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/wxdatecalc)



# Tramite flatpak (consigliato perché ci sono le wxwidgets 3.2 invece che 3.0)
Date i seguenti comandi:

sudo apt install flatpak

flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

flatpak remote-add --if-not-exists numeronesoft http://numeronesoft.ddns.net:8080/numeronesoft.flatpakrepo

flatpak install --user org.altervista.numerone.wxdatecalc (è importante il --user, l'app viene installata in userspace, così si possono salvare le opzioni)

flatpak run org.altervista.numerone.wxdatecalc

# Tramite repository (con le wxwidgets 3.0)
Installate la nuova chiave del repository tramite il comando sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 52B68EEB

Poi inserite nel file /etc/apt/sources.list.d/numeronesoft.list la riga deb http://numeronesoft.ddns.net/ bullseye main

Infine fate apt update ed apt install wxdatecalc

# Compilazione con Flatpak
Installate flatpak con apt, aggiungete il repository uficiale, installate flatpakbuilder con flatpak poi installateflathub org.gnome.Platform//43
flathub org.gnome.Sdk//43
con flatpak e poi date il comando

flatpak run org.flatpak.Builder --repo=./repo ./build org.altervista.numerone.wxdatecalc.yml 
A questo punto il programma scaricherà e compilerà le ultime wxwidgets e l'ultimo wxdatecalc.

Infine dare il comando
flatpak run org.flatpak.Builder --user --install --force-clean ./build/ org.altervista.numerone.wxdatcalc.yml 

# Donazioni

[![paypal](https://www.paypalobjects.com/it_IT/IT/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=H4ZHTFRCETWXG)

Puoi donare anche tramite carta Hype a patto di avere il mio numero di cellulare nella rubrica. Sai dove lo puoi trovare? Sul mio curriculum.
Apri l'app Hype, fai il login, seleziona PAGAMENTI, INVIA DENARO, seleziona il mio numero nella rubrica, imposta l'importo, INSERISCI LA CAUSALE e segui le istruzioni a video.

