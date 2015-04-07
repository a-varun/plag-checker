import re
import difflib
def reg_match(word):
	p=re.compile('[" "]*[\t]*[a-z]*[(][int]*[float]*[ ]*')
	m=p.match(word)
	if m and "##printf" not in word:
		###print m,word
		return 1

def fuction_split(f1):
	sections=[]
	section=""
	i=0
	for line in f1:
		words=line.split(" ")
		flag=0
		i=0
		for word in words:
			if reg_match(word):
				flag=1
				break
			i=i+1
		if flag==1:
			sections.append(section)
			section=""
		section+=line
	sections.append(section)
	return sections

def get_html_markup_diflib(a,b,dif):
    htmla = '<div>'
    marka=[0 for i in range(len(a))]
    for block in dif.get_matching_blocks():
        l1=block[0]
        l2=block[2]
        l3=block[1]
        l4=block[2]
        for lim in range(l1,l1+l2):
            marka[lim]=1;
    i=0
    while i<len(a):
        if(a[i]=="\n"):
            htmla+='<br>'
            i=i+1
            continue
        if(a[i]=="\t"):
        	htmla+='&nbsp&nbsp&nbsp&nbsp'
        	i=i+1
        	continue
        if a[i]=="<":
        	if marka[i]==1:
        		htmla+='<mark>'
        	htmla+='&lt'
        	if marka[i]==1:
        		htmla+='</mark>'
        	i=i+1
        	continue
        if a[i]==">":
        	if marka[i]==1:
        		htmla+='<mark>'
        	htmla+='&gt'
        	if marka[i]==1:
        		htmla+='</mark>'
        	i=i+1
        	continue
        if marka[i]==1:
            htmla+= '<mark>'+a[i]+'</mark>'
        else:
            htmla+= a[i]
        i=i+1
    htmla+='</div>'
    return htmla

def obtain_codediff(a,b):
	f1=open(a,"r")
	f2=open(b,"r")
	s1=fuction_split(f1)
	s2=fuction_split(f2)
	htm1=""
	htm2=""
	html1=""
	totrat1=0.0
	totcnt1=0
	for sect1 in s1:
		rat=0.0
		for sect2 in s2:
			dif=difflib.SequenceMatcher(None,sect1,sect2)
			val=dif.ratio()
			if rat<val:
				rat=val
				htm1=get_html_markup_diflib(sect1,sect2,dif)
		totcnt1=totcnt1+1
		totrat1+=rat
		#print '-'*100
		#print htm1
		html1+=htm1
	#Percent1 contains percentage of match between file A and B
	percent1=totrat1/totcnt1
	##print percent1
	totcnt2=0
	totrat2=0.0
	html2=""
	for sect1 in s2:
		rat=0.0
		for sect2 in s1:
			dif=difflib.SequenceMatcher(None,sect1,sect2)
			val=dif.ratio()
			if rat<val:
				rat=val
				htm1=get_html_markup_diflib(sect1,sect2,dif)
		totcnt2=totcnt2+1
		totrat2+=rat
		html2+=htm1
	#Percent2 contains percentage of match between file B and A
	percent2=totrat2/totcnt2
	##print percent2
	return [[percent1, percent2], html1, html2]

