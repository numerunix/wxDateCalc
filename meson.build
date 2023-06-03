project('wxdatecalc', 'cpp', version: '0.1')
subdir('po')
wx_dep = dependency('wxwidgets', version : '>=3.0.0', required : true)
executable('org.altervista.numerone.wxdatecalc', ['wxDateCalcApp.cpp','wxDateCalcMain.cpp'], dependencies : [wx_dep], install: true

install_data('wxDateCalc.desktop', install_dir: 'usr/share/applications')
install_data('wxdatecalc.png', install_dir: 'usr/share/icons')

