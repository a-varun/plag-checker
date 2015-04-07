
'use strict';

var PlagiarismControllers = angular.module('PlagiarismControllers', []);

PlagiarismControllers.controller('IndexController',['$scope',function($scope) {
    $scope.title = 'About Project';
    $scope.content ="Need to check plagiarism in code?\
    You have come to the right site.\
    We aim at providing the service without the need for you to register.\
    Checkout our tool in action, and do leave feedback!";

    $scope.whatWeContent=["Compare two codes and check the percentage of match between them",
    "Display matched portion of the two codes",
    "Display the matched portions of the assembly code"];

}]);
