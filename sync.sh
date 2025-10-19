#!/bin/bash

gstatus=$(git status --porcelain)

if [ ${#gstatus} -ne 0 ]; then
  git add --all
  sleep 2
  git commit -m "Automated sync: $(echo "$gstatus" | tr '\n' '; ')"
  sleep 2
  git pull --rebase
  sleep 2
  git push
fi

