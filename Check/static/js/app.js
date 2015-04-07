'use strict';

/* App Module */
{% load staticfiles %}

var phonecatApp = angular.module('PlagiarismDetection', [
  'ngRoute',
  'PlagiarismControllers'
]);

phonecatApp.config(['$routeProvider',
  function($routeProvider) {
    $routeProvider.
      when('/', {
        templateUrl: "{% static 'partials/indexData.html' %}",
        controller: 'IndexController'
      }).
      when('/aboutus', {
        templateUrl: "{% static 'partials/aboutus.html' %} ",
        controller: 'IndexController'
      }).
      otherwise({
        redirectTo: '/'
      });
  }]);