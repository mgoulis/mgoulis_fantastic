Goulis's Space Adventure
Game Design Document
===================================

**Summary**
-Players will pilot the USS Magic Fantastic across the solar system to return home
-There will be 3 levels populated by varous enemies that will need to be dispaced

Level 1: Dangerous Departure
	There will be an series of incomming ships and asteroids the player will need to evade
	The player wil scroll toward enemies at a fixed pace and can move left and right
	The player can shoot a limitied number of amunition with the 'l' key
Lavel 2: Unfriendly Universe
	Similar to the last level but now enemies at a fixed position will shoot on a timed interval
Level 3: Final Frenzy
	Fixed position enemies encluded but now high speed incoming comets and irregularly moving spaceships introduced


**Controls**
Players will be able to use "a" and "d" to move left and right (standard WASD) 
Players will be able to shoot a bullet with 'l'
Special weapons can be activated with spacebar

**Score**
Completing levels 1 and 2 will reward 1000 points each
Completing the final level gives 2500 points
Killing an enemy earns 50 points
Collecting A Powerup earns 150 points

**Lives**
Players are given 3 lives at the start of the game
Every 1000 points earned will grant another life
Players are only allowed to be hit once before their ship explodes and they lose 1 life


**Sample Layout**


Your ship will move upward toward the top of the screen until you meet a checkered finish line
Top Of The Screen==========================================
		 =	          Score  		  =
		 =		 			  =
		 =					  =
		 =					  =
		 =               Enemies		  =
		 =		  Will  		  =
		 =		Be Around		  =
		 =		This Area		  =
		 =					  =
		 =					  =
		 =		 			  =
		 =					  =
		 =					  =
		 =		 			  =
		 =					  =
		 =					  =
		 =		 			  =
		 =					  =
        	 =		      ^			  =
	 	 =Player ship Here:  / \		  =
	 	 =					  =
	   	 =	            Life Boxes Here: $$$  =
Bottom Of The Screen=======================================


Menu Screen

Top Of The Screen==========================================
		 =	                		  =
		 =		 			  =
		 =					  =
		 =		********		  =
		 =             * TITLE  *	 	  =
		 =		********		  =
		 =					  =
		 =		 START			  =
		 =	      STAGE SELECT		  =
		 =	      HOW TO PLAY		  =
		 =		 			  =
		 =		HIGH SCORES		  =
		 =		1.			  =
		 =		2.			  =
		 =		3.			  =
		 =		4.			  =
		 =		5.			  =
		 =					  =
        	 =		      			  =
	 	 =					  =
	 	 =					  =
	   	 =	            			  =
Bottom Of The Screen=======================================


********MOVING OBJECTS********

**Player Ship**
     ^
<-- / \ -->
Moves left and right and can shoot projectiles up

**Asteroids**
	&&&~~~~~~
       &&&&&~~~~~~~
	&&&~~~~~~
Oncaming fixed path obstacles

**Cargo Ships**
  \$/
  ($)
Oncoming ships that move in a wave like pattern

**Satelite**
  ==0==
Wide objects that bounce left and right at very high speeds

**Space Station**
   ||
 ==00==
   ||
Fixed Object that shoots in 4 directions on a timed interval

**UFO**
  ***
  *0*
  ***
Spherical ship that shoots in a random direction every second
movement is irrefular

**Commet**
   #
   #
  ###
  QQQ
 QQQQQ
  QQQ
Fast oncoming object that is not hurt by standard bullets





