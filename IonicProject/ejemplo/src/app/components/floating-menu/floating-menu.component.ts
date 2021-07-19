import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { NavController } from '@ionic/angular';
import { UserService } from 'src/app/services/user.service';
import { UserData } from 'src/app/types/models';

@Component({
  selector: 'app-floating-menu',
  templateUrl: './floating-menu.component.html',
  styleUrls: ['./floating-menu.component.scss'],
})
export class FloatingMenuComponent implements OnInit {

  showMe = false;
  userData: UserData;

  constructor(
    private userService: UserService,
    private navController: NavController,
    private router: Router
  ) {}

  ngOnInit() {
    this.userService.userStatusChange.subscribe((userData: UserData) => {
      if (userData) {
        this.userData = userData;
        this.showMe = true;
        console.log({userData});
      } else {
        this.showMe = false;
        this.userData = null;
      }
    });
  }

  performLogout() {
    this.userService.performLogout();
    this.showMe = false;
    this.userData = null;
    // this.router.navigate(['/login']);
    this.navController.navigateBack('/login');
  }

  goToCreate() {
    this.navController.navigateForward('/create');
  }
}
