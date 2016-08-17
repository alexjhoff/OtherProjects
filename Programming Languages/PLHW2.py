from Tkinter import *
from random import randint 
from time import sleep,time 
from math import sqrt

#Draw a Canvas for the game
H=600
W= 800
window=Tk()
window.title("Submarine Game")
c=Canvas(window, width= W, height=H, bg="#CAE1FF" ) 
c.pack()

#Draw a red submarine
ship_c=c.create_oval(300,400,400,430, outline= "red", fill="red") 
ship_h=c.create_polygon(370,415,425,400,425,430, outline= "red", fill="red") 
ship_p=c.create_rectangle(350,387,360,400, outline= "red", fill="red") 
ship_p2=c.create_rectangle(340,387,350,390, outline= "red", fill="red")
#move the submarine 
#move up
SHIP_SPD=10
def move_ship_up(event):
	x1,y1,x2,y2 =c.coords(ship_c) 
	if y1-SHIP_SPD > 0:
		c.move(ship_c,0,-SHIP_SPD) 
		c.move(ship_h,0,-SHIP_SPD) 
		c.move(ship_p,0,-SHIP_SPD) 
		c.move(ship_p2,0,-SHIP_SPD)
window.bind("<Up>", move_ship_up)

#move down 
SHIP_SPD1=-10
def move_ship_down(event):
	x1,y1,x2,y2 =c.coords(ship_c) 
	if y2-SHIP_SPD1 < 640:
		c.move(ship_c,0,-SHIP_SPD1) 
		c.move(ship_h,0,-SHIP_SPD1) 
		c.move(ship_p,0,-SHIP_SPD1) 
		c.move(ship_p2,0,-SHIP_SPD1)
window.bind("<Down>", move_ship_down)

#move right
SHIP_SPD2=0
def move_ship_right(event):
	x1,y1,x2,y2 =c.coords(ship_c) 
	if x1-SHIP_SPD1 < 730:
		c.move(ship_c,10,-SHIP_SPD2) 
		c.move(ship_h,10,-SHIP_SPD2) 
		c.move(ship_p,10,-SHIP_SPD2) 
		c.move(ship_p2,10,-SHIP_SPD2)
window.bind("<Right>", move_ship_right)

#moveleft
SHIP_SPD3=0
def move_ship_left(event):
	x1,y1,x2,y2 =c.coords(ship_c) 
	if x2-SHIP_SPD1 > 80:
		c.move(ship_c,-10,-SHIP_SPD3) 
		c.move(ship_h,-10,-SHIP_SPD3) 
		c.move(ship_p,-10,-SHIP_SPD3)
		c.move(ship_p2,-10,-SHIP_SPD3) 
window.bind("<Left>", move_ship_left)

bubble_id=list() 
bubble_r=list() 
bubble_speed=list()

#create mine
def create_mines():
	mineX = randint(20,750)
	mineY = randint(20,550)
	mineRad = randint(20,70)
	mineSpeed = randint(1,3)
	drawMine = c.create_oval(mineX, mineY, mineX+mineRad, mineY+mineRad)

	bubble_id.append(drawMine)
	bubble_r.append(mineRad)
	bubble_speed.append(mineSpeed)

#move bubbles up
def mov_mines():
	for x in range(0, len(bubble_id)):
		c.move(bubble_id[x], 0, -randint(1,5))

#calculate distance
def Cdistance(x):
	#ship and mine coords
	x1,y1,x2,y2 = c.coords(ship_c)
	a1,b1,a2,b2 = c.coords(bubble_id[x])
	#ship and mine distances apart
	shipX = (x1+x2)/2
	shipY = (y1+y2)/2
	mineX = (a1+a2)/2
	mineY = (b1+b2)/2
	distance = ((mineX-shipX)**2 + (mineY-shipY)**2)**0.5
	return distance

score=0
#calculate collision
def collision():
	i = 0
	while i < len(bubble_id):
		distance = Cdistance(i)
		if(distance < bubble_r[i]):
			global score
			score = score + 1
			c.delete(bubble_id[i])
			del (bubble_id[i])
			del (bubble_r[i])
			del (bubble_speed[i])
		i = i + 1

c.create_text(150,30, text='SCORE', fill="black") 
score_text = c.create_text(150, 50, fill='black') 
def show_score(score):
	c.itemconfig(score_text, text=str(score))

NUM_MINES = 25
#main game loop
for x in range(0,NUM_MINES):
	create_mines() #you need to create this function 
while time()<END:
	mov_mines() #you need to create this function
	if randint(1,5)==1: #this will create a new bubble every certain amount of time
		create_mines()
	#clean_up_mines() #you need to create this function 
	collision() #you need to create this function 
	show_score(score)
	window.update()
	sleep(0.1)


