#!/usr/bin/env python3

from bs4 import BeautifulSoup
import requests
import json
import sys
import pypandoc

SESSION_KEY='INSERT_YOUR_SESSION_KEY_HERE'

DESCR_URL = 'http://adventofcode.com/2017/day/{}'
DESCR = 'descriptions/Day{:02}.md'

INPUT_URL = 'http://adventofcode.com/2017/day/{}/input'
INPUT = 'inputs/Day{:02}.txt'

session = dict(session=SESSION_KEY)

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
