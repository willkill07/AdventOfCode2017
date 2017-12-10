#!/usr/bin/env python3

from bs4 import BeautifulSoup
import requests
import json
import sys
import pypandoc

URL = 'http://adventofcode.com/2017/day/{}'
OUT = 'Day{:02}.md'

session = dict(session='SESSION KEY GOES HERE')

def download(day):
  r = requests.get(URL.format(day), cookies=session)
  soup = BeautifulSoup(r.text, "html5lib")
  with open(OUT.format(day), 'w') as of:
    for part in soup('article'):
      of.write(pypandoc.convert_text(str(part), 'html', format='markdown'))

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("Usage: {} <day>".format(sys.argv[0]))
  else:
    download(int(sys.argv[1]));
