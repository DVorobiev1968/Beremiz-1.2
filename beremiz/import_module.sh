#!/bin/bash
echo Install for Python 3.6
#pip3 install -U -f https://extras.wxpython.org/wxPython4/extras/linux/gtk3/ubuntu-18.04 wxPython
echo Install for libs

#sudo apt-get install -y libgtk2.0-dev \
#libgtk-3-dev \
#libjpeg-dev \
#libtiff-dev \
#libsdl1.2-dev \
#libnotify-dev \
#freeglut3 \
#freeglut3-dev \
#libsm-dev \
#libwebkitgtk-dev \
#libwebkitgtk-3.0-dev

echo install package for make documentation
sudo apt-get -y install make \
python-sphinx \
python-sphinx-rtd-theme \
doxygen \
graphviz \
python-breathe \
breathe-doc \
texlive-base \
texlive-latex-base \
texlive-lang-cyrillic \
texlive-fonts-recommended \
texlive-generic-extra \
texlive-latex-extra \
texlive-latex-recommended

echo wxPython package for Python 2.7
#pip install wxPython