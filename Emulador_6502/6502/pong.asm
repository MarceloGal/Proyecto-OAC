init:
lda #$0f ; ypos
sta $18 ; ball
sta $19 ; plr1
sta $1a ; plr2
lda #$1d ; xpos
sta $0a ; plr2
lda #$02
sta $08 ; ball
sta $09 ; plr1
lsr
sta $20 ; xdir (ball)
sta $21 ; ydir (ball)

mainloop:
dec $dd ; delay
bne mainloop
lda #$c0 ; change to modify game speed
sta $dd
inc $a1 ; ai sleep timer
jsr redraw
lda $18 ; ypos (ball) + ydir (ball)
adc $21
cmp #$20
bcc withinbounds
txa ; = 0 here
sbc $21
sta $21
clc
adc $18
withinbounds:
sta $18
jsr ai ; plr1 movements
jsr moveplr ; plr2 movements
clc
lda $08 ; xpos (ball) + xdir (ball)
adc $20
sta $08
cmp #$20
bcs init
cmp #$02 
beq testplr1
cmp #$1d
bne mainloop

testplr2:
lda $18
sbc $1a
cmp #$03
bcs mainloop
lda #$ff
bcc deflect

testplr1:
lda $18 
sbc $19
cmp #$03
bcs mainloop
lda #$01

deflect:
sta $20
bcc mainloop

redraw:
txa ; set colors of all objects to black at old positions
jsr draw 
lda #$03 ; set to cyan at new positions
draw:
sta $0c
ldx #$03
drawloop:
lda #$00
sta $d0
ldy $87,x
lda $97,x
lsr
ror $d0
lsr
ror $d0
lsr
ror $d0
adc #$02
sta $d1
lda $07,x
sta $87,x
lda $17,x
sta $97,x
lda $0c
sta ($d0),y
dex
beq redrawn
tya
ora #$20
tay
lda $0c
sta ($d0),y
tya
eor #$60
tay
lda $0c
sta ($d0),y
bpl drawloop
redrawn:
rts

ai:
ldy $19 ; ai plr ypos
bit $20
bmi aisetgoal ; if ball closes in on ai plr use accu (= ball ypos here)

lda #$10 ; else center position 

aisetgoal:
sta $30 ; desired ai ypos
dec $30
lda $a1
and #$0f ; every 16th iteration skip ai to make it beatable
beq endai
cpy $30
beq aihold
bcs aiup
iny
aihold:
iny
aiup:
dey
cpy #$1e
bcs endai
sty $19
endai:
rts

moveplr:
ldy $1a
lda $ff ; ascii code of last input
cmp #$2b
beq plrdown ; if = "+"
bcc plrmoved 
dey ; if > "+" (e.g. "-")
dey
plrdown:
iny
cpy #$1e
bcs plrmoved
sty $1a
sty $ff ; write something < "+" to input to allow single step movement
plrmoved:
rts