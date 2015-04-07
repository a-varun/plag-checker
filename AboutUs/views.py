from django.shortcuts import render

from django.http import HttpResponse


def AboutUs(request):
    context = {'latest_question_list': 'something'}
    return render(request, 'AboutUs/AboutUs.html', context)