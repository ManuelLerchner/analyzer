  $ cfgDot 19-if-0.c

  $ graph-easy --as=boxart main.dot
                                                           ┌────────────────────────────────┐
                                                           │ main()                         │
                                                           └────────────────────────────────┘
                                                             │
                                                             │ (body)
                                                             ▼
  ┌────────────────────────────────┐                       ┌────────────────────────────────┐
  │ 19-if-0.c:15:9-15:27           │                       │ 19-if-0.c:9:5-16:5             │
  │ (19-if-0.c:15:9-15:27)         │                       │ (19-if-0.c:9:9-9:10)           │
  │ YAML loc: true, loop: false    │                       │ YAML loc: true, loop: false    │
  │ YAMLval loc: true, loop: false │  Neg(0)               │ YAMLval loc: true, loop: false │
  │ GraphML: true; server: true    │ ◀──────────────────── │ GraphML: true; server: true    │
  └────────────────────────────────┘                       └────────────────────────────────┘
    │                                                        │
    │                                                        │ Pos(0)
    │                                                        ▼
    │                                                      ┌────────────────────────────────┐
    │                                                      │ 19-if-0.c:11:9-11:16           │
    │                                                      │ (19-if-0.c:11:9-11:16)         │
    │                                                      │ YAML loc: true, loop: false    │
    │                                                      │ YAMLval loc: true, loop: false │
    │                                                      │ GraphML: true; server: true    │
    │                                                      └────────────────────────────────┘
    │                                                        │
    │                                                        │ stuff()
    │                                                        ▼
    │                                                      ┌────────────────────────────────┐
    │                                                      │ 19-if-0.c:17:5-17:13           │
    │                                                      │ (unknown)                      │
    │                                                      │ YAML loc: true, loop: false    │
    │                                __goblint_check(1)    │ YAMLval loc: true, loop: false │
    └────────────────────────────────────────────────────▶ │ GraphML: true; server: true    │
                                                           └────────────────────────────────┘
                                                             │
                                                             │ return 0
                                                             ▼
                                                           ┌────────────────────────────────┐
                                                           │ return of main()               │
                                                           └────────────────────────────────┘
