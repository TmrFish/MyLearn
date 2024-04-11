studs = [{'sid':'103', 'Chinese': 90, 'Math':95, 'English':92},
        {'sid':'101', 'Chinese': 80, 'Math':85, 'English':82},
        {'sid':'102', 'Chinese': 70, 'Math':75, 'English':72}]


def sc():
        scores = {}
        for i in range(0, len(studs) ):
                a = studs[i]
                b = eval(a['sid'])
                c = [a['Chinese'], a['Math'], a['English']]
                scores.update({b:c})
                scores =dict(sorted(scores.items(), key=lambda x: x[0]))

        for i in scores:
                print('{}:{}'.format(i,scores[i]))

sc()