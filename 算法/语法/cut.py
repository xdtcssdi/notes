

def Forword_cut(text, dict):
    _dic, _size = dict
    size = _size
    cuts = []
    i = 0
    while i < len(text):
        _part = text[i:i + size]
        if _part in _dic:
            i += size
            size = _size
            cuts.append(_part)
        else:
            size -= 1
            if size == 0:
                size = _size
                i += 1
                cuts.append(_part)
                
    return cuts

def Backward_cut(text, dict):
    _dic, _size = dict
    size = _size
    cuts = []
    i = len(text)
    while i:
        _part = text[i - size :i]
        if _part in _dic:
            i -= size
            size = _size
            cuts.append(_part)
        else:
            size -= 1
            if size == 0:
                size = _size
                i -= 1
                cuts.append(_part)
    cuts.reverse()
    return cuts

def bilateral(text, dict):
    l1 = Forword_cut(text, dict)
    l2 = Backward_cut(text, dict)
    if len(l1) < len(l2):
        return l1
    else:
        return l2

if __name__ == "__main__":
    
    dict = ['南京市', '长江大桥', '市长','长江', '大桥']

    cuts = Forword_cut('南京市长江大桥', (dict, 3))

    print(cuts)

    cuts = Backward_cut('南京市长江大桥', (dict, 4))

    print(cuts)

    cuts = bilateral('南京市长江大桥', (dict, 4))

    print(cuts)
