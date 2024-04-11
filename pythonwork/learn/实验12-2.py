wen = "Python is an easy to learn, powerful programming language. " \
      "It has efficient high-level data structures and a simple but " \
      "effective approach to object-oriented programming. Python's elegant" \
      " syntax and dynamic typing, together with its interpreted nature," \
      " make it an ideal language for scripting and rapid application development" \
      " in many areas on most platforms.The Python interpreter and the extensive standard" \
      " library are freely available in source or binary form for all major platforms from " \
      "the Python Web site, https://www.python.org/, and may be freely distributed. The same " \
      "site also contains distributions of and pointers to many free third party Python modules," \
      " programs and tools, and additional documentation."
x = wen.split()
wordcount = {}
a = []
b = 0
for i in x:
    print(i)

    if i in a:
        b = wordcount[i]
        b += 1
        wordcount.update({i: b})
        b = 0
    else:
        a.append(i)
        b += 1
        wordcount.update({i: b})
        b = 0
wordcount =dict(sorted(wordcount.items(), key=lambda x: x[1],reverse=True))
for i in range (0,3):
    print("{: <5}:{}".format(list(wordcount.keys())[i],list(wordcount.values())[i]))

