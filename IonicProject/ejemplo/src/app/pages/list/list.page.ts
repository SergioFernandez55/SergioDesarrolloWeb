import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { ModalController } from '@ionic/angular';
import { ViewNoteComponent } from 'src/app/components/view-note/view-note.component';
import { NotesService } from 'src/app/services/notes.service';
import { Note } from 'src/app/types/models';
import { ActionSheetController } from '@ionic/angular';

@Component({
  selector: 'app-list',
  templateUrl: './list.page.html',
  styleUrls: ['./list.page.scss'],
})
export class ListPage implements OnInit {
  notes: Note[] = [];

  constructor(
    private noteService: NotesService,
    public modalController: ModalController,
    private router: Router,
    private actionSheetController: ActionSheetController) {}

  ngOnInit() {
    //Sacamos las notas del servicio de notas
    this.notes = this.noteService.notes;
    console.log(this.notes);
  }

  async viewNote(noteId: number) {
    console.log('note: ' + noteId);
    const modal = await this.modalController.create({
      component: ViewNoteComponent,
      componentProps: {
        noteId
      }
    });
    return await modal.present();
  }

  goToEdit(noteId: number) {
    this.noteService.currentNote = noteId;
    this.router.navigate(['/edit']);
  }

  deleteNote(nodeId: number){
    this.noteService.deleteNote(nodeId);
  }

  async presentActionSheet(nodeId: number) {
    const actionSheet = await this.actionSheetController.create({
      header: this.notes[nodeId-1].title,
      cssClass: 'my-custom-class',
      buttons: [{
        text: 'Borrar',
        role: 'destructive',
        icon: 'trash',
        handler: () => {
          this.deleteNote(nodeId);
        }
      }, {
        text: 'Otros',
        icon: 'gift',
        handler: () => {
          console.log('Others clicked');
        }
      }, {
        text: 'Editar',
        icon: 'chatbubble-ellipses-outline',
        handler: () => {
          this.goToEdit(nodeId);
        }
      }, {
        text: 'Ver nota',
        icon: 'chevron-up-circle-outline',
        handler: () => {
          this.viewNote(nodeId);
        }
      }, {
        text: 'Cancelar',
        icon: 'close',
        role: 'cancel',
        handler: () => {
          console.log('Cancel clicked');
        }
      }]
    });
    await actionSheet.present();

    const { role } = await actionSheet.onDidDismiss();
    console.log('onDidDismiss resolved with role', role);
  }
}
