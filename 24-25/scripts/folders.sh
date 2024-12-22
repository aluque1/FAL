#! /bin/bash
for ((i=$2; i<=$3; i++))
do
  mkdir ~/Desktop/uni/FAL/24-25/$1/"p$i"
  mv ~/Downloads/samples-$i.zip ~/Desktop/uni/FAL/24-25/$1/p$i
  mv ~/Downloads/p$i.pdf ~/Desktop/uni/FAL/24-25/$1/p$i
  cd ~/Desktop/uni/FAL/24-25/$1/p$i
  sh ~/scripts/fal/prepEx.sh
  cd ..
done