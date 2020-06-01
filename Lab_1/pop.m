function val = pop

    global top st
    val = st{top};
top = top -1;