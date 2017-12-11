#!/usr/bin/env python3

from bs4 import BeautifulSoup
import requests
import json
import sys
import pypandoc

DESCR_URL = 'http://adventofcode.com/2017/day/{}'
DESCR = 'descriptions/Day{:02}.md'

INPUT_URL = 'http://adventofcode.com/2017/day/{}/input'
INPUT = 'inputs/Day{:02}.txt'

session = dict(session='53616c7465645f5f5a6732379ded1cf9f1d404e4a852cc7b118eab3d3393816270032eee75cba85a601c0ccf225f2a2d')

def downloadDesc(day):
  r = requests.get(DESCR_URL.format(day), cookies=session)
  soup = BeautifulSoup(r.text, "html5lib")
  data = '\n'.join(str(p) for p in soup('article'))
  pypandoc.convert_text(data, 'markdown', format='html', outputfile=DESCR.format(day))

def downloadInput(day):
  r = requests.get(INPUT_URL.format(day), cookies=session)
  with open(INPUT.format(day), 'w') as of:
    of.write(r.text)

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("Usage: {} <day>".format(sys.argv[0]))
  else:
    day = int(sys.argv[1])
    downloadDesc(day)
    downloadInput(day)
